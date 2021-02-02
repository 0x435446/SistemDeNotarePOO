#include "Game.h"



std::vector <Sun*> map_suns;
std::vector <Plants*> shooting_plants;
std::vector <Plants*> all_plants;
std::vector <ShopPlants*> shop_plants;
std::vector <int> rows = { 8, 13, 18 ,23, 28 };
std::vector <int> cols = { 7,12,17,22,27,32,37,42,47 };
std::vector <Projectiles*> proiectile;
std::vector <Zombie*> enemies;
std::map <std::string, int> players;
std::string player_name;

int coins = 0;
int level = 0;
int score = 0;
int level1_enemies = 3;
int level2_enemies = 6;
int level3_enemies = 10;


int SunSpawnTime = 4500;

#define ZombieSpawnTime 7000


void doLoadingBar()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "*";

	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > 150)
	{
		begin = end;
		conOut(ROW_TITLE + 1, col) << printedChar;
		if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS) {
			if (printedChar == "*")
			{
				printedChar = " ";
			}
			else
			{
				printedChar = "*";
			}
			col = COL_FIRST_STAR_POSITION;
		}
		else
		{
			col += COL_DISTANCE_BETWEEN_STARS;
		}
	}
}

bool find_player(std::string player_name)
{
	for (auto x = players.begin(); x != players.end(); x++)
	{
		if (x->first == player_name)
		{
			level = x->second;
			return true;
		}
	}
	return false;
}

Game *Game::instance = nullptr;
UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
int column = 7;

Game::Game()
{
	Game::readPlayersList();
	Game::screenEntry();
	Game::mainMenu();
	Map::drawMap();
	conOut(1, 1) << "Scor\n";
	Game::drawShop();
	Game::writePlayers();
	int toPlant = 0;
	while (true)
	{
		Game::checkWin();
		conOut(2, 1) << score;
		Game::levels();
		if (score == 150)
			level = 2;
		if (score == 450)
			level = 3;
		conOut(5, 70) << "Coins: " << coins << "      ";

		// spawneaza sori
		Game::spawnSuns();

		// preluam actiunea
		std::string action = conIn.getUserActions();
		Action A(action);
		
		// save
		Game::save(A);

		// plantam ce s-a selectat din shop
		Game::plant(A,toPlant);

		// verificam daca s-a selectat un soare sau ceva din shop
		Game::verifySelection(A, toPlant);

		// proiectilele
		Game::drawProjectiles();

		// mouse event
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 15);
		if (action != "a")
			conOut(41, 2) << action;
		else
			break;
	}
}

Game::~Game()
{
}

Game& Game::getInstance()
{
	// TODO: insert return statement here
	if (!Game::instance)
	{
		Game::instance = new Game();
	}
	return *Game::instance;
}

void Game::spawnSuns()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	static auto begin = steady_clock::now();
	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > SunSpawnTime && map_suns.size()<=9)
	{
		begin = end;
		conOut(3, column) << (char)(178);
		map_suns.push_back(new Sun(column, 3));
		column += 5;
	}
	if (column == 52)
		column = 7;
}

void Game::plant(Action A, int& toPlant)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	std::vector<int>::iterator it;
	if (toPlant == 1)
	{
		if (A.getAction() == "clicked")
		{
			it = std::find(rows.begin(), rows.end(), A.getY());
			if (it != rows.end())
			{
				auto x = std::find(cols.begin(), cols.end(), A.getX());
				if (x != cols.end())
				{
					all_plants[all_plants.size() - 1]->setXY(A.getX(), A.getY());
					//for shooting plants
					if (all_plants[all_plants.size() - 1]->getName() == "P")
					{
						shooting_plants.push_back(new PlantPeaShooter(PeaShooterHealth, "P", PeaShooterTime));
						shooting_plants[shooting_plants.size() - 1]->setXY(A.getX(), A.getY());
					}
					if (all_plants[all_plants.size() - 1]->getName() == "S")
					{
						shooting_plants.push_back(new PlantFrozenPea(FrozenPeaShooterHealth, "S", FrozenPeaShooterTime));
						shooting_plants[shooting_plants.size() - 1]->setXY(A.getX(), A.getY());
					}
					conOut(A.getY(), A.getX()) << all_plants[all_plants.size() - 1]->getName();
					if (all_plants[all_plants.size() - 1]->getName() == "s")
						SunSpawnTime -= 500;
					toPlant = 0;
				}
			}
			else
			{
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 15);
				conOut(20, 75) << "Nu ati pus o pozitie corecta!       ";
			}
		}
	}
}

void Game::verifySelection(Action A, int &toPlant)
{
	if (A.getAction() == "clicked")
	{
		for (auto x = map_suns.begin(); x != map_suns.end(); x++)
		{

			if (A.getY() == 3 && A.getX() == (*x)->getX())
			{
				conOut(3, A.getX()) << " ";
				coins += (*x)->getMoney();
				map_suns.erase(x);
				break;
			}
		}
		for (auto x = shop_plants.begin(); x != shop_plants.end(); x++)
		{
			if (A.getX() == 2 && A.getY() == (*x)->getX())
			{
				if ((*x)->getCost() <= coins)
				{
					coins -= (*x)->getCost();
					if ((*x)->getName() == "P")
					{
						all_plants.push_back(new PlantPeaShooter(PeaShooterHealth, "P", PeaShooterTime));
						toPlant = 1;
					}
					if ((*x)->getName() == "s")
					{
						all_plants.push_back(new PlantSunflower(SunFlowerHealth, "s"));
						toPlant = 1;
					}
					if ((*x)->getName() == "B")
					{
						all_plants.push_back(new PlantCherryBomb(CherryBombHealth, "B", CherryBombDamage));
						toPlant = 1;
					}
					if ((*x)->getName() == "S")
					{
						all_plants.push_back(new PlantFrozenPea(FrozenPeaShooterHealth, "S", FrozenPeaShooterTime));
						toPlant = 1;
					}
					if ((*x)->getName() == "W")
					{
						all_plants.push_back(new PlantWallNut(WallNutHealth, "W"));
						toPlant = 1;
					}
				}
			}
		}
	}
}

void Game::drawProjectiles()
{
	for (auto x = shooting_plants.begin(); x != shooting_plants.end(); x++)
	{
		if ((*x)->testTime())
		{
			if((*x)->getName()=="S")
				proiectile.push_back(new FrozenPeaProjectile((*x)->getX() + 1, (*x)->getY(), DamageFrozenPeaProjectile, FrozenPeaProjectileFrequency, FrozenPeaValueAbility));
			if ((*x)->getName() == "P")
				proiectile.push_back(new PeaProjectile((*x)->getX() + 1, (*x)->getY(), DamagePeaProjectile, PeaProjectileFrequency));
		}
	}
	for (int i = 0; i < proiectile.size(); i++)
	{
		int hit = 0;
		if (proiectile[i]->testTime() && hit == 0)
		{
			proiectile[i]->move();
		}
		if (proiectile[i]->getX() + 1 == 50)
		{
			conOut(proiectile[i]->getY(), 49) << " ";
			delete proiectile[i];
			proiectile.erase(proiectile.begin() + i);
			continue;
		}
		if (enemies.size() == 0)
			break;
		for (int j = 0; j < enemies.size(); j++)
		{
			if ((proiectile[i]->getX() + 1 == enemies[j]->getX()) || (proiectile[i]->getX() + 2 == enemies[j]->getX()))
			{
				if (proiectile[i]->getY() == enemies[j]->getY())
				{
					conOut(proiectile[i]->getY(), proiectile[i]->getX()) << " ";
					enemies[j]->takeDamage(proiectile[i]->getDamage());
					if (proiectile[i]->getAbility() != 0)
						enemies[j]->slowMovement(proiectile[i]->getAbility());
					delete proiectile[i];
					proiectile.erase(proiectile.begin() + i);
					break;
				}
			}
		}
	}
}

void Game::drawShop()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13);
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(7, 2) << "P";
	conOut(8, 2) << "50";
	shop_plants.push_back(new ShopPlants("P", 50, 7, 2));
	conOut(12, 2) << "s";
	conOut(13, 2) << "25";
	shop_plants.push_back(new ShopPlants("s", 25, 12, 2));
	conOut(17, 2) << "B";
	conOut(18, 2) << "100";
	shop_plants.push_back(new ShopPlants("B", 100, 17, 2));
	conOut(22, 2) << "S";
	conOut(23, 2) << "75";
	shop_plants.push_back(new ShopPlants("S", 75, 22, 2));
	conOut(27, 2) << "W";
	conOut(28, 2) << "50";
	shop_plants.push_back(new ShopPlants("W", 50, 27, 2));
}

void Game::combat()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		int fight = 0;

		//zombie win

		if (enemies[i]->getX() == 6)
		{
			conOut(enemies[i]->getY(), enemies[i]->getX()) << " ";
			delete enemies[i];
			enemies.erase(enemies.begin() + i);
			Game::gameOver();
			continue;
		}

		//death

		if (enemies[i]->getHealth() <= 0)
		{
			conOut(enemies[i]->getY(), enemies[i]->getX()) << " ";
			delete enemies[i];
			enemies.erase(enemies.begin() + i);
			score += 50;
			continue;
		}

		// colision cu o planta

		for (int j = 0; j < all_plants.size(); j++)
		{
			if ((enemies[i]->getX() - 1 == all_plants[j]->getX()) && (enemies[i]->getY() == all_plants[j]->getY()))
			{
				int check = 0;
				if ((enemies[i]->getName() == "X" || enemies[i]->getName() == "$") && (enemies[i]->getAbilityCharges() != 0))
				{
					check = 1;
					enemies[i]->decreaseCharges();
					conOut(enemies[i]->getY(), enemies[i]->getX()) << " ";
					enemies[i]->modifyX(2);
					conOut(enemies[i]->getY(), enemies[i]->getX()) << enemies[i]->getName();
				}
				if (all_plants[j]->getName() == "B" && check == 0)
				{
					fight = 1;
					for (int q = 0; q < enemies.size(); q++)
					{
						if (abs(all_plants[j]->getX() - enemies[q]->getX()) <= 2)
						{
							if (all_plants[j]->getY() == enemies[q]->getY())
								enemies[q]->takeDamage(all_plants[j]->getDamage());
						}
						else
						{
							if ((all_plants[j]->getY() == enemies[q]->getY()) || (all_plants[j]->getY() + 5 == enemies[q]->getY()) || (all_plants[j]->getY() - 5 == enemies[q]->getY()))
							{
								if ((all_plants[j]->getX()-6 <= enemies[q]->getX()) && (all_plants[j]->getX() + 6 >= enemies[q]->getX()))
								{
									enemies[q]->takeDamage(all_plants[j]->getDamage() / 2);
								}
							}
						}
					}
					conOut(all_plants[j]->getY(), all_plants[j]->getX()) << " ";
					delete all_plants[j];
					all_plants.erase(all_plants.begin() + j);
				}
				else
				{
					fight = 1;
					static auto b = steady_clock::now();
					auto e = steady_clock::now();
					if (duration_cast<milliseconds>(e - b).count() > 2500)
					{
						b = e;
						conOut(20, 75) << all_plants[j]->getHealth();
						if (all_plants[j]->getHealth() <= 0)
						{
							fight = 0;
							if (all_plants[j]->getName() == "s")
								SunSpawnTime += 500;
							conOut(all_plants[j]->getY(), all_plants[j]->getX()) << " ";
							delete all_plants[j];
							all_plants.erase(all_plants.begin() + j);
						}
						else
								all_plants[j]->takeDamage(enemies[i]->getDamage());
						break;
					}
				}
			}
		}
		if (enemies[i]->testTime() && fight == 0)
		{
			enemies[i]->move();
		}
	}
}

void Game::levels()
{
	int coordY;
	std::random_device device;
	std::mt19937 generator{ device() };
	std::uniform_int_distribution<int> distribution(1, 5);
	int zombieLine = distribution(generator);
	if (zombieLine == 1)
		coordY = 8;
	if (zombieLine == 2)
		coordY = 13;
	if (zombieLine == 3)
		coordY = 18;
	if (zombieLine == 4)
		coordY = 23;
	if (zombieLine == 5)
		coordY = 28;
	static auto begin_enemies = steady_clock::now();
	auto end_enemies = steady_clock::now();
	if (duration_cast<milliseconds>(end_enemies - begin_enemies).count() > ZombieSpawnTime && level1_enemies != 0)
	{
		conOut(12, 75) << "Wave 1!";
		--level1_enemies;
		begin_enemies = end_enemies;
		enemies.push_back(new Zombie(ZombieHealth, ZombieSpeed, ZombieDamage, "Z", 49, coordY));
	}
	else
	{
		if (duration_cast<milliseconds>(end_enemies - begin_enemies).count() > ZombieSpawnTime && level2_enemies != 0 && level == 2)
		{
			conOut(12, 75) << "Wave 2!";
			begin_enemies = end_enemies;
			if ((level2_enemies == 6) || (level2_enemies == 5))
				enemies.push_back(new Zombie(ZombieHealth, ZombieSpeed, ZombieDamage, "Z", 49, coordY));
			else
			{
				if ((level2_enemies == 4) || (level2_enemies == 3))
					enemies.push_back(new BucketHeadZombie(BucketHeadZombieHealth, BucketHeadZombieSpeed, BucketHeadZombieDamage, "H", 49, coordY));
				else
				{
					if (level2_enemies == 2)
						enemies.push_back(new PoleVaultingZombie(PoleVaultingZombieHealth, PoleVaultingZombieSpeed, PoleVaultingZombieDamage, "X", 49, coordY, 1));
					else
						enemies.push_back(new SuperZombie(SuperZombieHealth, SuperZombieSpeed, SuperZombieDamage, "$", 49, coordY, 1));
				}
			}
			--level2_enemies;
		}
		if (duration_cast<milliseconds>(end_enemies - begin_enemies).count() > ZombieSpawnTime && level3_enemies != 0 && level == 3)
		{
			conOut(12, 75) << "Wave 3!";
			begin_enemies = end_enemies;
			if (level3_enemies > 7)
				enemies.push_back(new Zombie(ZombieHealth, ZombieSpeed, ZombieDamage, "Z", 49, coordY));
			else
			{
				if (level3_enemies <= 7 && level3_enemies >= 4)
					enemies.push_back(new BucketHeadZombie(BucketHeadZombieHealth, BucketHeadZombieSpeed, BucketHeadZombieDamage, "H", 49, coordY));
				else
				{
					if (level3_enemies == 2 || level3_enemies == 3)
						enemies.push_back(new PoleVaultingZombie(PoleVaultingZombieHealth, PoleVaultingZombieSpeed, PoleVaultingZombieDamage, "X", 49, coordY, 1));
					else
						enemies.push_back(new SuperZombie(SuperZombieHealth, SuperZombieSpeed, SuperZombieDamage, "$", 49, coordY, 1));
				}
			}
			--level3_enemies;
		}
	}
	Game::combat();
}

void Game::checkWin()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (score == 950)
	{
		Sleep(2000);
		SetConsoleTextAttribute(hConsole, 14);
		Game::clearScreen();
		std::ifstream fin("win_image.txt");
		char* text = new char[256];
		for (int i = 8; i <= 18; i++)
		{
			fin.getline(text, 256);
			conOut(i, 64) << text;
		}
		fin.close();
		std::ofstream fout("highscores.txt", std::ios::app);
		fout << player_name << " " << score << "\n";
		fout.close();
		conOut(21, 70) << "Press any key to exit...      ";
		_getch();
		exit(0);
	}
}

void Game::screenEntry()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 11);
	std::ifstream fin("Title.txt");
	char* text = new char[256];
	for (int i = 15; i <= 23; i++)
	{
		fin.getline(text, 256);
		conOut(i, 35) << text;
	}
	conOut(25, 76) << "Press any key to continue...\n";
	_getch();
	Game::clearScreen();
	conOut(0, 0);
}

void Game::mainMenu()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	std::ifstream fin("MainMenu.txt");
	char* text = new char[256];
	for (int i = 15; i <= 20; i++)
	{
		fin.getline(text, 256);
		conOut(i, 60) << text;
	}
	SetConsoleTextAttribute(hConsole, 14);
	conOut(21, 79) << "New Game\n";
	conOut(23, 79) << "Load Game\n";
	conOut(25, 79) << "Highscores\n";
	while (true)
	{
		std::string action = conIn.getUserActions();
		Action A(action);
		if (A.getX() >= 79 && A.getX() < 89)
		{
			if (A.getY() == 21)
			{
				Game::newGame();
				break;
			}
			if (A.getY() == 23)
			{
				Game::loadGame();
				break;
			}
			if (A.getY() == 25)
			{
				Game::showHighscores();
				break;
			}
		}
		if (action != "a")
			conOut(41, 2) << action;
		else
			break;
	}
}

void Game::newGame()
{
	Game::clearScreen();
	while (true)
	{
		conOut(20, 70);
		std::cout<<"Player name:\n" << std::flush;
		std::cin >> player_name;
		conOut(20, 83) << player_name << "\n";
		_getch();
		if (find_player(player_name) == false)
		{
			level = 1;
			players.insert(std::pair<std::string, int>(player_name, level));
			conOut(21, 70) << "Press any key to continue...";
			_getch();
			break;
		}
		else
		{
			conOut(20, 70) << "The name already exist!             ";
			conOut(21, 70) << "Press any key to choose other name...            ";
			_getch();
			conOut(20, 70) << "                                        ";
			conOut(21, 70) << "                                        ";
		}
	}
	conOut(20, 70) << "                             ";
	conOut(21, 70) << "                             ";
	conOut(0, 0);
}

void Game::loadGame()
{
	Game::clearScreen();
	while (true)
	{
		conOut(20, 70) << "Player name: \n";
		std::cin >> player_name;
		conOut(20, 83) << player_name << "\n";
		if (find_player(player_name) == false)
		{
			conOut(20, 70) << "The name don't exist!                            ";
			conOut(21, 70) << "Press any key to choose other name...            ";
			_getch();
			conOut(20, 70) << "                                        ";
			conOut(21, 70) << "                                        ";
		}
		else
		{
			if (level == 2)
			{
				level1_enemies = 0;
				score = 150;
			}
			if (level == 3)
			{
				level1_enemies = 0;
				level2_enemies = 0;
				score = 450;
			}
			break;
		}
	}
	_getch();
	conOut(20, 70) << "                                         ";
	conOut(0, 0);
}

void Game::readPlayersList()
{
	std::string name;
	int level;
	std::ifstream fin("players.txt");
	while (fin.peek() != EOF)
	{
		fin >> name;
		fin >> level;
		players.insert(std::pair<std::string,int>(name,level));
	}
}

void Game::save(Action A)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	conOut(2, 90) << "SAVE!";
	if (A.getY() == 2)
	{
		if (A.getX() >= 90 && A.getX() <= 95)
		{
			for (auto x = players.begin(); x != players.end(); x++)
			{
				if (x->first == player_name)
					x->second = level;
			}
			Game::writePlayers();
		}
	}
}

void Game::clearScreen()
{
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 300; j++)
		{
			conOut(i, j) << " ";
		}
	}
}

void Game::gameOver()
{
	Game::clearScreen();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::ifstream fin("GameOver.txt");
	char* text = new char[256];
	int k = 12;
	for (int i = 15; i <= 23; i++)
	{
		SetConsoleTextAttribute(hConsole, k);
		if (i == 20)
			k = 14;
		fin.getline(text, 256);
		conOut(i, 65) << text;
	}
	SetConsoleTextAttribute(hConsole, 14);
	conOut(25, 76) << "Press any key to continue...\n";
	std::ofstream fout("highscores.txt", std::ios::app);
	fout << player_name << " " << score << "\n";
	fout.close();
	_getch();
	exit(0);
}

void Game::writePlayers()
{
	std::ofstream fout("players.txt");
	for (auto x = players.begin(); x != players.end(); x++)
	{
		fout << x->first << " " << x->second << "\n";
	}
	fout.close();
}

void Game::showHighscores()
{
	Game::clearScreen();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	std::ifstream fin("highscores_image.txt");
	char* text = new char[256];
	for (int i = 8; i <= 16; i++)
	{
		fin.getline(text, 256);
		conOut(i, 60) << text;
	}
	fin.close();
	std::vector<std::string> names;
	std::vector<int> scoruri;         // lista de highscores
	std::ifstream f("highscores.txt");
	std::string name;
	int x, row=16;
	while (f.peek() != EOF)
	{
		f >> name >> x;
		names.push_back(name);
		scoruri.push_back(x);
	}
	f.close();
	for (int i = 0; i < names.size(); i++)
	{
		for (int j = i; j < names.size(); j++)
		{
			if (scoruri[i] < scoruri[j])
			{
				int aux = scoruri[i];
				scoruri[i] = scoruri[j];
				scoruri[j] = aux;
				swap(names[i], names[j]);
			}
		}
	}
	SetConsoleTextAttribute(hConsole, 14);
	for (int i = 0; i < names.size(); i++)
	{
		conOut(row, 81) << names[i] << " " << scoruri[i] << "\n";
		row++;
	}
	conOut(row + 1, 70) << "Press any key to go to Main Menu...\n";
	_getch();
	Game::clearScreen();
	Game::mainMenu();
}

void Game::deleteInstance()
{
	if (Game::instance)
	{
		delete Game::instance;
		Game::instance = nullptr;
	}
}
