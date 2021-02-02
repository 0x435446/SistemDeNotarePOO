#include "GameManager.h"

using namespace GameMechanics;

GameManager* GameManager::instance = nullptr;

GameManager::GameManager() : GUI(UserInterface::GUI::getInstance()), playerManager(PlayerManager::getInstance()),
logger(Debugging::Logger::getInstance())
{
	currentScore = 0;
	status = GameStatus::ONGOING;
}

GameManager::~GameManager()
{
}


GameManager& GameManager::getInstance()
{
	if (instance == nullptr)
		instance = new GameManager;
	return *instance;
}

void GameManager::destroyInstance()
{
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}


void GameManager::loginPlayer()
{
	while (true)
	{
		std::string name = GUI.getPlayerInfo("name");
		Sleep(500);
		std::string password = GUI.getPlayerInfo("password");

		currentPlayer = playerManager.loadPlayer(name, password);
		if (currentPlayer != nullptr)
		{
			logger.log("User " + name + " was logged in succesfully.");
			break;
		}
	}
	currentLevel = currentPlayer->getLevel() + 1;
}

void GameManager::initialiseScene()
{
	GUI.drawInfo(currentPlayer->getName(), currentPlayer->getHighscore());
	logger.log("Level scene was initialised.");
}

void GameManager::initialiseLevel()
{
	level = new Level(currentLevel);

	for (unsigned i = 0; i < PLANTS_ID.size(); i++)
	{
		if (level->plantDefaultStatus[PLANTS_ID[i]] == PlantStatus::LOCKED)
			plantsStatus[PLANTS_ID[i]] = PlantStatus::LOCKED;
		else if (currentResources >= PLANTS_COST[i])
			plantsStatus[PLANTS_ID[i]] = PlantStatus::AVAILABLE;
		else
			plantsStatus[PLANTS_ID[i]] = PlantStatus::NOT_ENOUGH_RESOURCES;
		timeSinceLastSpawn.push_back(0);
	}

	int midRowUp = UserInterface::BOARD_ROW_UP + 2 * UserInterface::TILE_HEIGHT;

	if (level->lanesNo == 1)
		GUI.drawLane(midRowUp, UserInterface::BOARD_COL_LEFT);
	else if (level->lanesNo == 3)
		for (int j = 0; j < level->lanesNo; j++)
			GUI.drawLane(UserInterface::BOARD_ROW_UP + (1 + j) * UserInterface::TILE_HEIGHT, UserInterface::BOARD_COL_LEFT);
	else
		for (int j = 0; j < level->lanesNo; j++)
			GUI.drawLane(UserInterface::BOARD_ROW_UP + j * UserInterface::TILE_HEIGHT, UserInterface::BOARD_COL_LEFT);

	GUI.showLevelNo(currentLevel);

	timeAtLevelStart = std::chrono::steady_clock::now();
	isAPlantSelected = false;
	currentWave = 0;
	initialiseWave();
	level->spawnedSuper = false;
	currentResources = 500;

	logger.log("Level " + std::to_string(currentLevel) + " was initialised");
}

void GameManager::endLevel()
{
	logger.log("Level cleared.");
	status = GameStatus::LEVEL_CLEAR;
	GUI.showGameStatus(status);
	Sleep(2000);
	delete level;
	currentScore += (unsigned)resources.size() * 10;
	GUI.updateInfo(currentScore, currentResources, timeElapsed, currentWave, level->wavesNo, isPaused);
	updatePlayerInfo();
	initialiseScene();
	currentLevel++;

	clearEntities<Enemy>(enemies);
	clearEntities<Plant>(plants);
	clearEntities<Resource>(resources);
	clearEntities<Projectile>(projectiles);

	status = GameStatus::ONGOING;
	GUI.showGameStatus(status);
	playGame();
}

void GameManager::initialiseWave()
{
	toSpawnNo.clear();
	for (unsigned i = 0; i < ENEMIES_ID.size(); i++)
		toSpawnNo.push_back(level->enemiesNo[i]);
	if (level->spawnedSuper)
		toSpawnNo[ENEMIES_ID.size() - 1] = 0;
	isPaused = true;
	timePaused = 0;
	logger.log("Wave " + std::to_string(currentWave) + " initialised.");
}

void GameManager::clearTile(unsigned rowUp, unsigned colLeft)
{
	GUI.eraseTile(rowUp, colLeft);
	for (auto e : plants)
		if (e->getRowUp() == rowUp)
			if (colLeft< e->getColLeft() && colLeft + UserInterface::TILE_WIDTH > e->getColLeft())
				displayEntity(e);
	for (auto e : projectiles)
		if (e->getRowUp() == rowUp)
			if (colLeft< e->getColLeft() && colLeft + UserInterface::TILE_WIDTH > e->getColLeft())
				displayEntity(e);
	for (auto e : enemies)
		if (e->getRowUp() == rowUp)
			if (colLeft< e->getColLeft() && colLeft + UserInterface::TILE_WIDTH > e->getColLeft())
				displayEntity(e);
}

void GameManager::displayEntity(UserInterface::IDrawable* entity)
{
	if (entity->getColLeft() >= UserInterface::BOARD_COL_LEFT && entity->getColLeft() < UserInterface::BOARD_COL_LEFT + (COLS_NO - 1) * (UserInterface::TILE_WIDTH - 1))
		entity->draw(' ');
}

void GameManager::calculateTimeElapsed()
{
	auto timeNow = std::chrono::steady_clock::now();
	timeElapsed = (int)std::chrono::duration_cast<std::chrono::seconds>((timeNow - timeAtLevelStart) * 2).count();
}

void GameManager::updatePositions()
{
	static int lastUpdated = 0;

	if (lastUpdated == timeElapsed)
		return;

	std::vector<Projectile*> collided;
	for (auto pr : projectiles)
	{
		if (pr->getSpeed() != 0)
		{
			if (pr->getColLeft() == UserInterface::BOARD_COL_LEFT + (COLS_NO - 1) * (UserInterface::TILE_WIDTH - 1) - 1)
				collided.push_back(pr);
			else if (timeElapsed%pr->getSpeed() == 0)
			{
				pr->move();
				displayEntity(pr);
			}
		}
		if (pr->getColliding())
			collided.push_back(pr);
	}

	for (auto toRemove : collided)
	{
		auto it = std::find(projectiles.begin(), projectiles.end(), toRemove);
		if (it != projectiles.end())
		{
			GUI.eraseProjectile((*it)->getRowUp(), (*it)->getColLeft());
			logger.log(logDespawn(*it));
			delete *it;
			projectiles.erase(it);
		}
	}

	for (auto et : enemies)
		if (timeElapsed%et->getSpeed() == 0)
		{
			et->move();
			if (et->getColLeft() > UserInterface::BOARD_COL_LEFT)
				displayEntity(et);
		}

	for (auto pl : plants)
		pl->draw();

	lastUpdated = timeElapsed;
}

void GameManager::checkResourceSpawning()
{
	static int lastUpdated = 0;

	if (lastUpdated == timeElapsed)
		return;

	if (timeElapsed%level->resourceRate == 0)
	{
		srand((unsigned)time(NULL));
		int chosenResource = rand() % RESOURCES_ID.size();

		spawnResource(RESOURCES_ID[chosenResource]);
	}

	lastUpdated = timeElapsed;
}

void GameManager::checkEnemySpawning()
{
	static int lastUpdated = 0;

	if (isPaused)
		return;

	if (lastUpdated == timeElapsed)
		return;

	if (timeElapsed % SPAWNING_RATE)
		return;

	int totalNo = 0;
	for (unsigned i = 0; i < toSpawnNo.size(); i++)
		totalNo += toSpawnNo[i];

	if (totalNo == 0)
		return;

	srand((unsigned)(time(NULL)));
	int chosen = rand() % totalNo;

	int partSum = 0;
	for (unsigned i = 0; i < ENEMIES_ID.size(); i++)
	{
		if (chosen >= partSum && chosen < toSpawnNo[i] + partSum)
		{
			spawnEnemy(ENEMIES_ID[i]);
			break;
		}
		partSum += toSpawnNo[i];
	}

	lastUpdated = timeElapsed;
}

void GameManager::checkProjectileSpawning()
{
	static int lastUpdated = 0;

	if (lastUpdated == timeElapsed)
		return;

	lastUpdated = timeElapsed;

	for (auto pl : plants)
		if (timeElapsed % pl->getShootRate() == 0)
		{
			EntityID toSpawn = pl->shoot();
			if (toSpawn == EntityID::NONE)
				continue;
			Projectile* p = nullptr;
			switch (toSpawn)
			{
			case EntityID::PEA:
				p = new Pea(pl->getRowUp(), pl->getColLeft());
				break;
			case EntityID::FROZENPEA:
				p = new FrozenPea(pl->getRowUp(), pl->getColLeft());
				break;
			case EntityID::EXPLOSION:
			{
				p = new Explosion(pl->getRowUp(), pl->getColLeft());
				pl->receiveDamage(pl->getRemainingHP());
				clearTile(pl->getRowUp(), pl->getColLeft());
				break;
			}
			default:
				break;
			}

			if (p == nullptr)
				throw Debugging::Exception(__func__, __FILE__, __LINE__, Debugging::SPAWN_ERROR);

			logger.log(logSpawn(p));

			displayEntity(p);
			projectiles.push_back(p);
		}

}

void GameManager::updatePlantStatuses()
{
	static int lastUpdated = 0;

	if (lastUpdated == timeElapsed)
		return;

	for (unsigned i = 0; i < PLANTS_ID.size(); i++)
		if (timeSinceLastSpawn[i])
		{
			timeSinceLastSpawn[i]--;
			if (timeSinceLastSpawn[i] == 0)
				plantsStatus[PLANTS_ID[i]] = PlantStatus::NOT_ENOUGH_RESOURCES;
		}

	lastUpdated = timeElapsed;

	for (unsigned i = 0; i < PLANTS_ID.size(); i++)
	{
		if (plantsStatus[PLANTS_ID[i]] == PlantStatus::NOT_ENOUGH_RESOURCES && PLANTS_COST[i] <= currentResources)
			plantsStatus[PLANTS_ID[i]] = PlantStatus::AVAILABLE;
		if (plantsStatus[PLANTS_ID[i]] == PlantStatus::AVAILABLE && PLANTS_COST[i] > currentResources)
			plantsStatus[PLANTS_ID[i]] = PlantStatus::NOT_ENOUGH_RESOURCES;
	}

	GUI.updatePlantsStatus(plantsStatus);
}

void GameManager::checkMouseEvent()
{
	std::string mouseEvent = GUI.getMouseEvent();

	if (mouseEvent == " ")
		return;

	//check for click on save, load, plants, resources, board

	unsigned delPos = (unsigned)mouseEvent.find_first_of(' ');
	unsigned row = stoi(mouseEvent.substr(0, delPos));
	unsigned col = stoi(mouseEvent.substr(delPos + 1));

	//Checking if a resource was clicked

	if (row > UserInterface::RESOURCE_AREA_ROW_UP && row < UserInterface::RESOURCE_AREA_ROW_UP + UserInterface::TILE_HEIGHT)
	{
		Resource *p = nullptr;
		for (auto r : resources)
			if (col > r->getColLeft() && col < r->getColLeft() + UserInterface::SUN_WIDTH)
			{
				currentResources += r->collectResources();
				p = r;
				break;
			}

		if (p)
		{
			auto it = std::find(resources.begin(), resources.end(), p);
			GUI.eraseTile(UserInterface::RESOURCE_AREA_ROW_UP, p->getColLeft());
			logger.log(logDespawn(p));
			resources.erase(it);
			delete p;
		}
	}

	//Checking if a plant was selected

	if (col > UserInterface::PLANT_AREA_COL_LEFT && col < UserInterface::PLANT_AREA_COL_LEFT + UserInterface::TILE_WIDTH)
	{
		for (int i = 0; i < ROWS_NO; i++)
			if (row > UserInterface::PLANT_AREA_ROW_UP + i * UserInterface::TILE_HEIGHT && row < UserInterface::PLANT_AREA_ROW_UP + (i + 1) * UserInterface::TILE_HEIGHT)
				if (plantsStatus[PLANTS_ID[i]] == PlantStatus::AVAILABLE)
				{
					if (isAPlantSelected)
						plantsStatus[currentPlantSelection] = PlantStatus::AVAILABLE;
					currentPlantSelection = PLANTS_ID[i];
					isAPlantSelected = true;
					plantsStatus[currentPlantSelection] = PlantStatus::SELECTED;
				}
	}

	//Checking if a tile was selected

	if (isAPlantSelected)
	{
		using UserInterface::TILE_HEIGHT;
		using UserInterface::TILE_WIDTH;
		using UserInterface::BOARD_ROW_UP;
		using UserInterface::BOARD_COL_LEFT;

		for (int i = 0; i < ROWS_NO; i++)
		{
			if (level->lanesNo == 1)
				if (i != 2)
					continue;
			if (level->lanesNo == 3)
				if (i == 0 || i == 4)
					continue;
			for (int j = 0; j < COLS_NO; j++)
				if ((row > BOARD_ROW_UP + i * TILE_HEIGHT && row < BOARD_ROW_UP + (i + 1)*TILE_HEIGHT) && (col > BOARD_COL_LEFT + j * (TILE_WIDTH - 1) && col < BOARD_COL_LEFT + (j + 1)*(TILE_WIDTH - 1)))
				{
					bool occupied = false;
					for (auto pl : plants)
						if (pl->getRowUp() == BOARD_ROW_UP + i * TILE_HEIGHT && pl->getColLeft() == BOARD_COL_LEFT + j * (TILE_WIDTH - 1))
						{
							occupied = true;
							break;
						}
					if (!occupied)
						spawnPlant(BOARD_ROW_UP + i * TILE_HEIGHT, BOARD_COL_LEFT + j * (TILE_WIDTH - 1));
				}
		}
	}

	//Checking if a button was clicked

	if (row >= UserInterface::SAVE_ROW_UP && row <= UserInterface::SAVE_ROW_UP + UserInterface::SPACE_DIST)
	{
		if (col >= UserInterface::SAVE_COL_LEFT && col <= UserInterface::SAVE_COL_LEFT + UserInterface::SAVE_WIDTH)
			saveGame();
		else if (col >= UserInterface::LOAD_COL_LEFT && col <= UserInterface::LOAD_COL_LEFT + UserInterface::LOAD_WIDTH)
			loadGame();
	}
}

void GameManager::checkIfPaused()
{
	static int lastUpdated = 0;

	if (lastUpdated == timeElapsed)
		return;

	if (timePaused >= level->pauseBetweenWaves)
	{
		isPaused = false;
		timePaused = 0;
		currentWave++;
	}

	if (isPaused)
		timePaused++;

	lastUpdated = timeElapsed;
}

void GameManager::checkEndOfWave()
{
	for (unsigned i = 0; i < toSpawnNo.size(); i++)
		if (toSpawnNo[i])
			return;

	for (auto en : enemies)
		if (en->getColLeft() <= UserInterface::BOARD_COL_LEFT)
		{
			logger.log("Game over.");
			status = GameStatus::LOSE;
			GUI.showGameStatus(status);
			Sleep(5000);
		}

	if (enemies.size())
		return;

	if (currentWave == level->wavesNo)
		endLevel();
	else
		initialiseWave();
}

void GameManager::checkForCollisions()
{
	static int lastUpdated = 0;

	if (lastUpdated == timeElapsed)
		return;

	for (auto en : enemies)
	{
		bool isColliding = false;
		for (auto pl : plants)
		{
			if (pl->getRowUp() == en->getRowUp() && (pl->getColLeft() <= en->getColLeft() && pl->getColLeft() + pl->getWidth() > en->getColLeft()))
			{
				if ((en->getID() != EntityID::POLEVAULTING && en->getID() != EntityID::SUPERZOMBIE) || (en->hasJumped()))
				{
					isColliding = true;
					pl->receiveDamage(en->causeDamage());
				}
				else
				{
					isColliding = true;
					clearTile(en->getRowUp(), en->getColLeft());
				}
				break;
			}
		}
		en->setColliding(isColliding);
	}

	for (auto pr : projectiles)
	{
		bool hasCollided = false;
		if (pr->getID() != EntityID::EXPLOSION)
		{
			for (auto en : enemies)
			{
				if (pr->getRowUp() == en->getRowUp() && (pr->getColLeft() + pr->getWidth() >= en->getColLeft() && pr->getColLeft() + pr->getWidth() <= en->getColLeft() + en->getWidth()))
				{
					hasCollided = true;
					en->receiveDamage(pr->causeDamage());
					en->receiveEffect(pr->getEffect());
					break;
				}
			}
			pr->setColliding(hasCollided);
		}
		else
		{
			unsigned r = pr->getRowUp();
			unsigned c = pr->getColLeft();

			unsigned diff = UserInterface::TILE_WIDTH / 2;

			for (auto en : enemies)
			{
				if (en->getRowUp() == r && (c <= en->getColLeft() + diff && c + UserInterface::TILE_WIDTH > en->getColLeft() + diff))
					en->receiveDamage(pr->causeDamage());
				else if ((en->getRowUp() == r - UserInterface::TILE_HEIGHT || en->getRowUp() == r + UserInterface::TILE_HEIGHT || en->getRowUp() == r)
					&& (c - UserInterface::TILE_WIDTH <= en->getColLeft() + diff && c + 2 * UserInterface::TILE_WIDTH > en->getColLeft() + diff))
					en->receiveDamage(pr->causeDamage() / 2);
			}
			pr->setColliding(true);
		}
	}

	lastUpdated = timeElapsed;
}

void GameManager::checkForDeaths()
{
	std::vector<Entity*> toBeRemoved;

	for (auto en : enemies)
		if (en->getRemainingHP() <= 0)
			toBeRemoved.push_back(en);

	for (auto r : toBeRemoved)
	{
		auto it = std::find(enemies.begin(), enemies.end(), r);
		clearTile((*it)->getRowUp(), (*it)->getColLeft());
		currentScore += (*it)->getPoints();
		logger.log(logDespawn(*it));
		delete *it;
		enemies.erase(it);
	}
	toBeRemoved.clear();

	for (auto pl : plants)
		if (pl->getRemainingHP() <= 0)
		{
			toBeRemoved.push_back(pl);
			if (pl->getID() == EntityID::SUNFLOWER)
				level->resourceRate++;
		}

	for (auto r : toBeRemoved)
	{
		auto it = std::find(plants.begin(), plants.end(), r);
		clearTile((*it)->getRowUp(), (*it)->getColLeft());
		logger.log(logDespawn(*it));
		delete *it;
		plants.erase(it);
	}
	toBeRemoved.clear();
}

std::string GameManager::logSpawn(Entity* e)
{
	std::string str = "A(n) ";
	str += GameMechanics::ENTITIES_NAMES[GameMechanics::getIndex(GameMechanics::ENTITIES_ID, e->getID())];
	str += " was spawned at (";
	str += std::to_string(e->getRowUp());
	str += ", ";
	str += std::to_string(e->getColLeft());
	str += ").";

	return str;
}

std::string GameManager::logDespawn(Entity* e)
{
	std::string str = "A(n) ";
	str += GameMechanics::ENTITIES_NAMES[GameMechanics::getIndex(GameMechanics::ENTITIES_ID, e->getID())];
	str += " was despawned at (";
	str += std::to_string(e->getRowUp());
	str += ", ";
	str += std::to_string(e->getColLeft());
	str += ").";

	return str;
}

void GameManager::spawnResource(EntityID chosenID)
{
	std::vector<int>freeCols;

	for (unsigned i = 0; i < COLS_NO; i++)
	{
		bool free = true;
		for (auto r : resources)
			if (r->getColLeft() == UserInterface::RESOURCE_AREA_COL_LEFT + i * (UserInterface::TILE_WIDTH - 1))
			{
				free = false;
				break;
			}
		if (free)
			freeCols.push_back(i);
	}

	if (freeCols.size() == 0)
		return;

	int chosenTile = freeCols[rand() % freeCols.size()];
	int r = UserInterface::RESOURCE_AREA_ROW_UP;
	int c = UserInterface::RESOURCE_AREA_COL_LEFT + chosenTile * (UserInterface::TILE_WIDTH - 1);

	Resource* spawned = nullptr;

	switch (chosenID)
	{
	case EntityID::SUN:
		spawned = new Sun(r, c);
		break;
	default:
		break;
	}

	if (spawned == nullptr)
		throw Debugging::Exception(__func__, __FILE__, __LINE__, Debugging::SPAWN_ERROR);

	logger.log(logSpawn(spawned));

	spawned->draw();
	resources.push_back(spawned);
}

void GameManager::spawnEnemy(EntityID chosenID)
{
	srand((unsigned)time(NULL));
	int chosenLane = rand() % level->lanesNo;
	if (level->lanesNo == 1)
		chosenLane += 2;
	else if (level->lanesNo == 3)
		chosenLane += 1;

	int r = UserInterface::BOARD_ROW_UP + chosenLane * UserInterface::TILE_HEIGHT;
	int c = UserInterface::BOARD_COL_LEFT + (COLS_NO - 1) * (UserInterface::TILE_WIDTH - 1);

	Enemy* spawned = nullptr;
	switch (chosenID)
	{
	case EntityID::ZOMBIE:
		spawned = new Zombie(r, c);
		break;
	case EntityID::BUCKETHEAD:
		spawned = new Buckethead(r, c);
		break;
	case EntityID::POLEVAULTING:
		spawned = new Polevaulting(r, c);
		break;
	case EntityID::SUPERZOMBIE:
		spawned = new SuperZombie(r, c);
		level->spawnedSuper = true;
		break;
	}

	auto index = getIndex(ENEMIES_ID, chosenID);
	toSpawnNo[index]--;

	if (spawned == nullptr)
		throw Debugging::Exception(__func__, __FILE__, __LINE__, Debugging::SPAWN_ERROR);

	logger.log(logSpawn(spawned));

	enemies.push_back(spawned);
	spawned->draw(' ');
}

void GameManager::spawnPlant(int row, int col)
{
	Plant* spawned = nullptr;
	switch (currentPlantSelection)
	{
	case EntityID::SUNFLOWER:
		spawned = new Sunflower(row, col);
		level->resourceRate = level->resourceRate > 1 ? level->resourceRate - 1 : 1;
		break;
	case EntityID::CHERRYBOMB:
		spawned = new CherryBomb(row, col);
		break;
	case EntityID::PEASHOOTER:
		spawned = new Peashooter(row, col);
		break;
	case EntityID::SNOWPEA:
		spawned = new SnowPea(row, col);
		break;
	case EntityID::WALLNUT:
		spawned = new Wallnut(row, col);
		break;
	default:
		break;
	}

	if (spawned == nullptr)
		throw Debugging::Exception(__func__, __FILE__, __LINE__, Debugging::SPAWN_ERROR);

	logger.log(logSpawn(spawned));

	plants.push_back(spawned);
	spawned->draw();

	auto index = getIndex(PLANTS_ID, currentPlantSelection);

	currentResources -= PLANTS_COST[index];
	timeSinceLastSpawn[index] = PLANTS_TIMEOUT[index];
	isAPlantSelected = false;
	plantsStatus[currentPlantSelection] = PlantStatus::UNAVAILABLE;
}

void GameManager::saveGame()
{
	currentPlayer->updateSavedData(serialize());
	logger.log("Game was saved.");
}

void GameManager::loadGame()
{
	logger.log("Game is loading");

	std::string s = currentPlayer->getSavedData();

	if (s == " ")
		return;
	delete this->level;

	clearEntities(enemies);
	clearEntities(plants);
	clearEntities(projectiles);
	clearEntities(resources);

	std::istringstream f(s);
	std::string line;

	std::getline(f, line);
	long timeStart = std::stol(line);
	std::getline(f, line);
	currentScore = std::stoi(line);
	std::getline(f, line);
	currentResources = std::stoi(line);
	std::getline(f, line);
	currentLevel = std::stoi(line);
	this->level = new Level(currentLevel);
	std::getline(f, line);
	this->level->spawnedSuper = std::stoi(line);
	std::getline(f, line);
	currentWave = std::stoi(line);
	std::getline(f, line);
	timeElapsed = std::stoi(line);
	{
		using namespace std::chrono;
		timeAtLevelStart = time_point<steady_clock>(steady_clock::now().time_since_epoch() - nanoseconds((long long)timeElapsed * 500000000L));
	}
	std::getline(f, line);
	timePaused = std::stoi(line);
	std::getline(f, line);
	isPaused = std::stoi(line);

	std::getline(f, line);
	int no = std::stoi(line);
	int temp;
	toSpawnNo.clear();
	for (int i = 0; i < no; i++)
	{
		f >> temp;
		toSpawnNo.push_back(temp);
	}

	deserializeEnemies(f);
	deserializePlants(f);
	deserializeProjectiles(f);
	deserializeResources(f);

	std::getline(f, line);
	no = std::stoi(line);
	int nr1, nr2;
	for (int i = 0; i < no; i++)
	{
		f >> nr1 >> nr2;
		plantsStatus[PLANTS_ID[nr1]] = PLANTS_STATUS[nr2];
	}

	f >> no;
	currentPlantSelection = PLANTS_ID[no];
	f >> no;
	for (int i = 0; i < no; i++)
		f >> timeSinceLastSpawn[i];

	int midRowUp = UserInterface::BOARD_ROW_UP + 2 * UserInterface::TILE_HEIGHT;

	GUI.cleanBoard();

	if (level->lanesNo == 1)
		GUI.drawLane(midRowUp, UserInterface::BOARD_COL_LEFT);
	else if (level->lanesNo == 3)
		for (int j = 0; j < level->lanesNo; j++)
			GUI.drawLane(UserInterface::BOARD_ROW_UP + (1 + j) * UserInterface::TILE_HEIGHT, UserInterface::BOARD_COL_LEFT);
	else
		for (int j = 0; j < level->lanesNo; j++)
			GUI.drawLane(UserInterface::BOARD_ROW_UP + j * UserInterface::TILE_HEIGHT, UserInterface::BOARD_COL_LEFT);

	GUI.showLevelNo(currentLevel);
	initialiseScene();
}

std::string GameManager::serialize()
{
	std::string s;

	long duration = std::chrono::duration_cast<std::chrono::milliseconds>(timeAtLevelStart.time_since_epoch()).count();
	s += std::to_string(duration);
	s += "\n";
	s += std::to_string(currentScore);
	s += "\n";
	s += std::to_string(currentResources);
	s += "\n";
	s += std::to_string(currentLevel);
	s += "\n";
	s += std::to_string(level->spawnedSuper);
	s += "\n";
	s += std::to_string(currentWave);
	s += "\n";
	s += std::to_string(timeElapsed);
	s += "\n";
	s += std::to_string(timePaused);
	s += "\n";
	s += std::to_string(isPaused);
	s += "\n";

	s += std::to_string(toSpawnNo.size());
	s += "\n";

	for (int i = 0; i < toSpawnNo.size(); i++)
	{
		s += std::to_string(toSpawnNo[i]);
		s += " ";
	}

	s += "\n";

	serializeVector(enemies, s);
	serializeVector(plants, s);
	serializeVector(projectiles, s);
	serializeVector(resources, s);

	s += std::to_string(plantsStatus.size());
	s += "\n";
	for (auto status : plantsStatus)
	{
		s += std::to_string(getIndex(PLANTS_ID, status.first));
		s += " ";
		s += std::to_string(getIndex(PLANTS_STATUS, status.second));
		s += "\n";
	}

	auto index = getIndex(PLANTS_ID, currentPlantSelection);
	s += std::to_string(index);
	s += "\n";

	s += std::to_string(timeSinceLastSpawn.size());
	s += "\n";

	for (int i = 0; i < timeSinceLastSpawn.size(); i++)
	{
		s += std::to_string(timeSinceLastSpawn[i]);
		s += " ";
	}

	s += "\n";

	return s;
}

void GameManager::deserializeEnemies(std::istringstream & s)
{
	std::string type;
	std::string line;

	std::getline(s, line);
	std::getline(s, line);
	int no = stoi(line);

	for (int i = 0; i < no; i++)
	{
		std::getline(s, type);
		std::getline(s, line);
		std::vector<int>tokens;
		size_t pos = 0;
		size_t nextpos = 0;
		while (nextpos != std::string::npos)
		{
			pos = nextpos;
			nextpos = line.find_first_of(' ', pos + 1);
			if (nextpos != std::string::npos)
				tokens.push_back(stoi(line.substr(pos, nextpos)));
			else
				tokens.push_back(stoi(line.substr(pos)));
		}

		Enemy *e = nullptr;
		unsigned index;

		if (type == "Zombie")
		{
			index = getIndex(ENEMIES_ID, EntityID::ZOMBIE);
			e = new Zombie(tokens[0], tokens[1]);
		}
		else if (type == "Buckethead")
		{
			index = getIndex(ENEMIES_ID, EntityID::BUCKETHEAD);
			e = new Buckethead(tokens[0], tokens[1]);
		}
		else if (type == "Polevaulting")
		{
			index = getIndex(ENEMIES_ID, EntityID::POLEVAULTING);
			e = new Polevaulting(tokens[0], tokens[1]);
			e->setJumped(tokens[6]);
		}
		else if (type == "SuperZombie")
		{
			index = getIndex(ENEMIES_ID, EntityID::SUPERZOMBIE);
			e = new SuperZombie(tokens[0], tokens[1]);
			e->setJumped(tokens[6]);
		}

		e->receiveDamage(ENEMIES_HP[index] - tokens[2]);
		e->receiveEffect(EFFECTS[tokens[3]]);
		e->setTimeInflicted(tokens[4]);
		e->setColliding(tokens[5]);

		enemies.push_back(e);
	}
}

void GameManager::deserializePlants(std::istringstream & s)
{
	std::string type;
	std::string line;

	std::getline(s, line);
	int no = stoi(line);

	for (int i = 0; i < no; i++)
	{
		std::getline(s, type);
		std::getline(s, line);
		std::vector<int>tokens;
		size_t pos = 0;
		size_t nextpos = 0;
		while (nextpos != std::string::npos)
		{
			pos = nextpos;
			nextpos = line.find_first_of(' ', pos + 1);
			if (nextpos != std::string::npos)
				tokens.push_back(stoi(line.substr(pos, nextpos)));
			else
				tokens.push_back(stoi(line.substr(pos)));
		}

		Plant *p = nullptr;
		unsigned index;

		if (type == "Peashooter")
		{
			index = getIndex(PLANTS_ID, EntityID::PEASHOOTER);
			p = new Peashooter(tokens[0], tokens[1]);
		}
		else if (type == "Sunflower")
		{
			index = getIndex(PLANTS_ID, EntityID::SUNFLOWER);
			p = new Sunflower(tokens[0], tokens[1]);
			this->level->resourceRate--;
		}
		else if (type == "Wallnut")
		{
			index = getIndex(PLANTS_ID, EntityID::WALLNUT);
			p = new Wallnut(tokens[0], tokens[1]);
		}
		else if (type == "CherryBomb")
		{
			index = getIndex(PLANTS_ID, EntityID::CHERRYBOMB);
			p = new CherryBomb(tokens[0], tokens[1]);
		}
		else if (type == "SnowPea")
		{
			index = getIndex(PLANTS_ID, EntityID::SNOWPEA);
			p = new SnowPea(tokens[0], tokens[1]);
		}

		p->receiveDamage(PLANTS_HP[index] - tokens[2]);
		plants.push_back(p);
	}
}

void GameManager::deserializeResources(std::istringstream & s)
{
	std::string type;
	std::string line;

	std::getline(s, line);
	int no = stoi(line);

	for (int i = 0; i < no; i++)
	{
		std::getline(s, type);
		std::getline(s, line);
		std::vector<int>tokens;
		size_t pos = 0;
		size_t nextpos = 0;
		while (nextpos != std::string::npos)
		{
			pos = nextpos;
			nextpos = line.find_first_of(' ', pos + 1);
			if (nextpos != std::string::npos)
				tokens.push_back(stoi(line.substr(pos, nextpos)));
			else
				tokens.push_back(stoi(line.substr(pos)));
		}

		Resource *r;

		if (type == "Sun")
			r = new Sun(tokens[0], tokens[1]);

		resources.push_back(r);
	}
}

void GameManager::deserializeProjectiles(std::istringstream & s)
{
	std::string type;
	std::string line;

	std::getline(s, line);
	int no = stoi(line);

	for (int i = 0; i < no; i++)
	{
		std::getline(s, type);
		std::getline(s, line);
		std::vector<int>tokens;
		size_t pos = 0;
		size_t nextpos = 0;
		while (nextpos != std::string::npos)
		{
			pos = nextpos;
			nextpos = line.find_first_of(' ', pos + 1);
			if (nextpos != std::string::npos)
				tokens.push_back(stoi(line.substr(pos, nextpos)));
			else
				tokens.push_back(stoi(line.substr(pos)));
		}

		Projectile *p = nullptr;
		unsigned index;

		if (type == "Pea")
		{
			index = getIndex(PROJECTILES_ID, EntityID::PEA);
			p = new Pea(tokens[0], tokens[1]);
		}
		else if (type == "FrozenPea")
		{
			index = getIndex(PROJECTILES_ID, EntityID::FROZENPEA);
			p = new FrozenPea(tokens[0], tokens[1]);
		}
		else if (type == "Explosion")
		{
			index = getIndex(PROJECTILES_ID, EntityID::EXPLOSION);
			p = new Explosion(tokens[0], tokens[1]);
		}

		p->setColliding(tokens[2]);
		projectiles.push_back(p);
	}
}

void GameManager::playGame()
{
	initialiseLevel();

	while (status == GameStatus::ONGOING)
	{
		calculateTimeElapsed();
		checkResourceSpawning();
		checkMouseEvent();
		updatePlantStatuses();
		checkIfPaused();
		checkEnemySpawning();
		checkProjectileSpawning();
		checkForCollisions();
		checkForDeaths();
		updatePositions();
		checkEndOfWave();
		GUI.updateInfo(currentScore, currentResources, timeElapsed / 2, currentWave, level->wavesNo, isPaused);
	}
}

void GameManager::updatePlayerInfo()
{
	currentPlayer->setHighscore(currentScore);
	currentPlayer->setLevel(currentLevel);
}

void GameManager::startGame()
{
	logger.log("Starting game.");
	loginPlayer();
	initialiseScene();
	playGame();
}