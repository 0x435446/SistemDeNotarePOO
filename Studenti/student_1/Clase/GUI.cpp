#include "GUI.h"

using namespace UserInterface;

GUI* GUI::gui = nullptr;

GUI::GUI() : conIn(ConsoleInput::getInstance()), conOut(ConsoleOutput::getInstance())
{
	loadSprites();

	initialiseWindow();
}

GUI::~GUI()
{
	for (auto s : sprites)
		delete s.second;
}


GUI &UserInterface::GUI::getInstance()
{
	if (gui == nullptr)
		gui = new GUI;
	return *gui;
}

void GUI::destroyInstance()
{
	if (gui != nullptr)
	{
		delete gui;
		gui = nullptr;
	}
}

std::string GUI::getPlayerInfo(std::string info)
{
	std::string str;


	int r = LOGIN_ROW_UP;
	int c = LOGIN_COL_LEFT;

	conOut[WhiteFore](r, c) << "Please type your " << info << " and press ENTER:";

	unsigned char old = ' ';

	r += SPACE_DIST;

	while (true)
	{
		unsigned char ch = conIn.getInstance().getChar();
		Sleep(125);

		if (ch != old)
		{
			if (ch == 0x0D && str.size() > 0) //ENTER
				break;
			else if (ch == 0x08) //BACKSPACE
			{
				if (str.size() > 0)
				{
					str.pop_back();
					c--;
					conOut(r, c) << " ";
				}
			}
			else if ((ch >= 'A' && ch <= 'Z'))
			{
				if (info != "password")
					conOut(r, c) << ch;
				else
					conOut(r, c) << "*";
				str.push_back(ch);
				c++;
			}
			old = ch;
		}
		else
			old = ' ';
	}

	conOut(LOGIN_ROW_UP, LOGIN_COL_LEFT) << "                                             ";
	conOut(LOGIN_ROW_UP + SPACE_DIST, LOGIN_COL_LEFT) << "                                             ";
	return str;
}

void UserInterface::GUI::drawInfo(std::string name, int highscore)
{
	conOut[BlackBack | MaroonFore](PLAYER_INFO_ROW_UP, PLAYER_INFO_COL_LEFT) << "Player: " << name;
	conOut[BlackBack | MaroonFore](PLAYER_INFO_ROW_UP + SPACE_DIST, PLAYER_INFO_COL_LEFT) << "High Score: " << highscore;

	conOut(SAVE_ROW_UP - 1, SAVE_COL_LEFT) << "----";
	conOut(SAVE_ROW_UP, SAVE_COL_LEFT - 1) << "|SAVE|";
	conOut(SAVE_ROW_UP + 1, SAVE_COL_LEFT) << "----";

	conOut(LOAD_ROW_UP - 1, LOAD_COL_LEFT) << "----";
	conOut(LOAD_ROW_UP, LOAD_COL_LEFT - 1) << "|LOAD|";
	conOut(LOAD_ROW_UP + 1, LOAD_COL_LEFT) << "----";

	conOut(SCORE_INFO_ROW_UP, SCORE_INFO_COL_LEFT) << "Score: ";
	conOut(SCORE_INFO_ROW_UP + SPACE_DIST, SCORE_INFO_COL_LEFT) << "Resources: ";
	conOut(SCORE_INFO_ROW_UP + 2 * SPACE_DIST, SCORE_INFO_COL_LEFT) << "Time: ";

	//Initialising the olive background
	for (unsigned i = 0; i < GameMechanics::PLANTS_ID.size(); i++)
		eraseTile(PLANT_AREA_ROW_UP + i * TILE_HEIGHT, PLANT_AREA_COL_LEFT);

	for (unsigned i = 0; i < GameMechanics::PLANTS_ID.size(); i++)
	{
		conOut[BlackBack | MaroonFore](PLANT_INFO_ROW_UP + i * TILE_HEIGHT, PLANT_INFO_COL_LEFT) << GameMechanics::plantsNames[i];
		conOut[BlackBack | MaroonFore](PLANT_INFO_ROW_UP + i * TILE_HEIGHT + SPACE_DIST, PLANT_INFO_COL_LEFT) << "Cost: " << GameMechanics::PLANTS_COST[i];
		sprites[GameMechanics::EntityID::TILE]->show(PLANT_AREA_ROW_UP + i * TILE_HEIGHT, PLANT_AREA_COL_LEFT);
		sprites[GameMechanics::PLANTS_ID[i]]->show(PLANT_AREA_ROW_UP + i * TILE_HEIGHT, PLANT_AREA_COL_LEFT);
	}

	drawLane(RESOURCE_AREA_ROW_UP, RESOURCE_AREA_COL_LEFT);

	for (int i = 0; i < GameMechanics::COLS_NO; i++)
		sprites[GameMechanics::EntityID::TILE]->show(RESOURCE_AREA_ROW_UP, RESOURCE_AREA_COL_LEFT + i * (TILE_WIDTH - 1)); //TILE_WIDTH - 1 pentru suprapunere
}

void UserInterface::GUI::showLevelNo(int l)
{
	conOut[BlackBack | MaroonFore](LEVEL_INFO_ROW_UP, LEVEL_INFO_COL_LEFT) << "Level " << l;
}

void GUI::cleanBoard()
{
	for (int r = BOARD_ROW_UP; r < BOARD_ROW_UP + TILE_HEIGHT * GameMechanics::ROWS_NO; r++)
		conOut[BlackBack | BlackFore](r, BOARD_COL_LEFT) << "                                                                                                                      ";
}

void UserInterface::GUI::showGameStatus(GameMechanics::GameStatus s)
{
	std::string str = " ";
	switch (s)
	{
	case GameMechanics::GameStatus::LOSE:
		str = "Game Over";
		break;
	case GameMechanics::GameStatus::LEVEL_CLEAR:
		str = "Level Clear!";
		break;
	case GameMechanics::GameStatus::ONGOING:
		str = "              ";
		break;
	}

	conOut[BlackBack | MaroonFore](LEVEL_INFO_ROW_UP + SPACE_DIST, LEVEL_INFO_COL_LEFT) << str;
}

void GUI::loadSprites()
{
	std::vector<std::pair <std::string, int> > v;

	//Zombie

	v.push_back(std::make_pair("zombie.txt", OliveBack | BlackFore));
	sprites[GameMechanics::EntityID::ZOMBIE] = new Sprite(v);
	v.clear();

	//Buckethead

	v.push_back(std::make_pair("bucketheadGear.txt", OliveBack | SilverFore));
	v.push_back(std::make_pair("bucketheadBody.txt", OliveBack | BlackFore));
	sprites[GameMechanics::EntityID::BUCKETHEAD] = new Sprite(v);
	v.clear();

	//Polevaulting

	v.push_back(std::make_pair("polevaultingGear.txt", OliveBack | SilverFore));
	v.push_back(std::make_pair("polevaultingBody.txt", OliveBack | BlackFore));
	sprites[GameMechanics::EntityID::POLEVAULTING] = new Sprite(v);
	v.clear();

	//SuperZombie

	v.push_back(std::make_pair("superGear.txt", OliveBack | SilverFore));
	v.push_back(std::make_pair("superBody.txt", OliveBack | BlackFore));
	sprites[GameMechanics::EntityID::SUPERZOMBIE] = new Sprite(v);
	v.clear();

	//Peashooter

	v.push_back(std::make_pair("peashooterBody.txt", OliveBack | GreenFore));
	v.push_back(std::make_pair("peashooterEyes.txt", OliveBack | WhiteFore));
	sprites[GameMechanics::EntityID::PEASHOOTER] = new Sprite(v);
	v.clear();

	//Sunflower

	v.push_back(std::make_pair("sunflowerBody.txt", OliveBack | GreenFore));
	v.push_back(std::make_pair("sunflowerCrown.txt", OliveBack | YellowFore));
	sprites[GameMechanics::EntityID::SUNFLOWER] = new Sprite(v);
	v.clear();

	//CherryBomb

	v.push_back(std::make_pair("cherryBody.txt", OliveBack | GreenFore));
	v.push_back(std::make_pair("cherryFruit.txt", OliveBack | RedFore));
	sprites[GameMechanics::EntityID::CHERRYBOMB] = new Sprite(v);
	v.clear();

	//Wallnut

	v.push_back(std::make_pair("wallnutBody.txt", OliveBack | WhiteFore));
	v.push_back(std::make_pair("wallnutEyes.txt", OliveBack | SilverFore));
	v.push_back(std::make_pair("wallnutMouth.txt", OliveBack | RedFore));
	sprites[GameMechanics::EntityID::WALLNUT] = new Sprite(v);
	v.clear();

	//SnowPea

	v.push_back(std::make_pair("peashooterBody.txt", OliveBack | BlueFore));
	v.push_back(std::make_pair("peashooterEyes.txt", OliveBack | WhiteFore));
	sprites[GameMechanics::EntityID::SNOWPEA] = new Sprite(v);
	v.clear();

	//Sun

	v.push_back(std::make_pair("sun.txt", OliveBack | YellowFore));
	sprites[GameMechanics::EntityID::SUN] = new Sprite(v);
	v.clear();

	//Pea

	v.push_back(std::make_pair("peaTrace.txt", OliveBack | OliveFore));
	v.push_back(std::make_pair("pea.txt", OliveBack | GreenFore));
	sprites[GameMechanics::EntityID::PEA] = new Sprite(v);
	v.clear();

	//Frozen pea

	v.push_back(std::make_pair("peaTrace.txt", OliveBack | OliveFore));
	v.push_back(std::make_pair("pea.txt", OliveBack | BlueFore));
	sprites[GameMechanics::EntityID::FROZENPEA] = new Sprite(v);
	v.clear();

	//Explosion

	v.push_back(std::make_pair("explosion.txt", OliveBack | RedFore));
	sprites[GameMechanics::EntityID::EXPLOSION] = new Sprite(v);
	v.clear();

	//Tile

	v.push_back(std::make_pair("tileMargins.txt", OliveBack | BlackFore));
	sprites[GameMechanics::EntityID::TILE] = new Sprite(v);
	v.clear();

	//Borders

	v.push_back(std::make_pair("borders.txt", MaroonFore));
	sprites[GameMechanics::EntityID::BORDERS] = new Sprite(v);
	v.clear();

	//Title

	v.push_back(std::make_pair("title.txt", UserInterface::BlueFore));
	sprites[GameMechanics::EntityID::TITLE] = new Sprite(v);
	v.clear();

	//Flowers

	v.push_back(std::make_pair("flowersCrown.txt", FuchsiaFore));
	v.push_back(std::make_pair("flowersBody.txt", GreenFore));
	sprites[GameMechanics::EntityID::FLOWERS] = new Sprite(v);
	v.clear();

	//Zombies

	v.push_back(std::make_pair("zombiesGear.txt", PurpleFore));
	v.push_back(std::make_pair("zombiesBody.txt", OliveFore));
	v.push_back(std::make_pair("zombiesGrass.txt", GreenFore));
	sprites[GameMechanics::EntityID::ZOMBIES] = new Sprite(v);
	v.clear();

	//Info

	v.push_back(std::make_pair("info.txt", MaroonFore));
	sprites[GameMechanics::EntityID::INFO] = new Sprite(v);
	v.clear();
}

void GUI::initialiseWindow()
{
	sprites[GameMechanics::EntityID::BORDERS]->show(AREA_ROW_UP, AREA_COL_LEFT);
	sprites[GameMechanics::EntityID::TITLE]->show(TITLE_ROW_UP, TITLE_COL_LEFT);
	sprites[GameMechanics::EntityID::FLOWERS]->show(BORDER_FLOWERS_ROW_UP, BORDER_FLOWERS_COL_LEFT);
	sprites[GameMechanics::EntityID::ZOMBIES]->show(BORDER_ZOMBIES_ROW_UP, BORDER_ZOMBIES_COL_LEFT);

	Debugging::Logger::getInstance().log("Main game window was initialised.");
}

Sprite* GUI::getSprite(GameMechanics::EntityID ID)
{
	return sprites[ID];
}

void UserInterface::GUI::updateInfo(int score, int resources, int time, int currentWave, int wavesNo, bool isPaused)
{
	static int oldScore = -1;
	static int oldResources = -1;

	if (oldScore != score)
	{
		conOut[BlackBack | MaroonFore](SCORE_INFO_ROW_UP, SCORE_INFO_COL_LEFT + (int)strlen("Score: ")) << score << "     ";
		oldScore = score;
	}
	if (oldResources != resources)
	{
		conOut[BlackBack | MaroonFore](SCORE_INFO_ROW_UP + SPACE_DIST, SCORE_INFO_COL_LEFT + (int)strlen("Resources: ")) << resources << "     ";
		oldResources = resources;
	}

	static int oldTime;
	if (oldTime != time)
	{
		std::string timeStr;
		int min = time / 60;
		int sec = time % 60;
		timeStr.push_back(min / 10 + '0');
		timeStr.push_back(min % 10 + '0');
		timeStr.push_back(':');
		timeStr.push_back(sec / 10 + '0');
		timeStr.push_back(sec % 10 + '0');
		oldTime = time;

		conOut[BlackBack | MaroonFore](SCORE_INFO_ROW_UP + 2 * SPACE_DIST, SCORE_INFO_COL_LEFT + strlen("Time: ")) << timeStr;
	}

	static bool oldPaused = false;
	static int oldWave = -1;
	if (currentWave != oldWave || oldPaused != isPaused)
	{
		oldWave = currentWave;
		oldPaused = isPaused;
		if (!isPaused)
			conOut[BlackBack | MaroonFore](SCORE_INFO_ROW_UP + 3 * SPACE_DIST, SCORE_INFO_COL_LEFT) << "Wave " << currentWave << "/" << wavesNo;
		else
			conOut[BlackBack | MaroonFore](SCORE_INFO_ROW_UP + 3 * SPACE_DIST, SCORE_INFO_COL_LEFT) << "                ";
	}
}

std::string UserInterface::GUI::getMouseEvent()
{
	return conIn.getMouseEvent();
}

void UserInterface::GUI::updatePlantsStatus(std::map<GameMechanics::EntityID, GameMechanics::PlantStatus> statuses)
{
	using GameMechanics::PlantStatus;
	using GameMechanics::PLANTS_ID;
	std::map< PlantStatus, std::string> strings = { {PlantStatus::AVAILABLE, "Available"}, {PlantStatus::LOCKED, "Locked"},
					{PlantStatus::NOT_ENOUGH_RESOURCES, "No resources" }, {PlantStatus::SELECTED, "Selected"}, {PlantStatus::UNAVAILABLE, "Unavailable"} };

	for (unsigned i = 0; i < PLANTS_ID.size(); i++)
	{
		conOut[BlackBack | MaroonFore](PLANT_INFO_ROW_UP + 2 * SPACE_DIST + i * TILE_HEIGHT, PLANT_INFO_COL_LEFT) << "               ";
		conOut[BlackBack | MaroonFore](PLANT_INFO_ROW_UP + 2 * SPACE_DIST + i * TILE_HEIGHT, PLANT_INFO_COL_LEFT) << strings[statuses[PLANTS_ID[i]]];
	}
}

void UserInterface::GUI::drawLane(unsigned rowUp, unsigned colLeft)
{
	conOut[OliveBack | BlackFore](rowUp, colLeft) << "+------------+------------+------------+------------+------------+------------+------------+------------+------------+";
	for (int i = 1; i < TILE_HEIGHT - 1; i++)
	{
		for (int j = 0; j < GameMechanics::COLS_NO; j++)
			conOut[OliveBack | BlackFore](rowUp + i, colLeft + j * (TILE_WIDTH - 1)) << "|            ";
		conOut[OliveBack | BlackFore](rowUp + i, colLeft + (GameMechanics::COLS_NO) * (TILE_WIDTH - 1)) << "|";
	}
	conOut[OliveBack | BlackFore](rowUp + TILE_HEIGHT - 1, colLeft) << "+------------+------------+------------+------------+------------+------------+------------+------------+------------+";
}

void UserInterface::GUI::eraseTile(unsigned rowUp, unsigned colLeft)
{
	std::vector<int> delimitationCols;

	for (int i = 0; i <= GameMechanics::COLS_NO; i++)
		delimitationCols.push_back(BOARD_COL_LEFT + i * (TILE_WIDTH - 1));

	conOut[OliveBack | BlackFore](rowUp, colLeft);

	for (int c = 0; c < TILE_WIDTH; c++)
		if (std::find(delimitationCols.begin(), delimitationCols.end(), c + colLeft) != delimitationCols.end())
			conOut << "+";
		else
			conOut << "-";

	for (int r = 1; r < TILE_HEIGHT - 1; r++)
	{
		conOut(rowUp + r, colLeft);
		for (int c = 0; c < TILE_WIDTH; c++)
			if (std::find(delimitationCols.begin(), delimitationCols.end(), c + colLeft) != delimitationCols.end())
				conOut[OliveBack | BlackFore] << "|";
			else
				conOut[OliveBack | OliveFore] << " ";
	}

	conOut[OliveBack | BlackFore](rowUp + TILE_HEIGHT - 1, colLeft);


	for (int c = 0; c < TILE_WIDTH; c++)
		if (std::find(delimitationCols.begin(), delimitationCols.end(), c + colLeft) != delimitationCols.end())
			conOut << "+";
		else
			conOut << "-";
}

void UserInterface::GUI::eraseProjectile(unsigned rowUp, unsigned colLeft)
{
	int r = rowUp + 3;
	int c = colLeft + 12;

	std::vector<int> delimitationCols;

	for (int i = 0; i <= GameMechanics::COLS_NO; i++)
		delimitationCols.push_back(BOARD_COL_LEFT + i * (TILE_WIDTH - 1));

	if (std::find(delimitationCols.begin(), delimitationCols.end(), c) != delimitationCols.end())
		conOut[BlackFore | OliveBack](r, c) << "|";
	else
		conOut[OliveBack | OliveFore](r, c) << " ";
}
