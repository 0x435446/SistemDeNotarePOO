#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
#include "Peashooter.h"
#include "Plant.h"
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include "Sun.h"
#include "Terrain.h"
#include "SetConsole.h"
#include "Sunflower.h"
#include "Player.h"
#include "Log.h"
#include "Wallnut.h"
#include "CherryBomb.h"


using namespace std::chrono;

Game* Game::instance = nullptr;

typedef struct coordMouse
{
	int x;
	int y;
};

coordMouse SlotInProximity(const coordMouse& cM, std::vector<std::pair<int,int>> slots)
{
	coordMouse m{ 0,0 };
	int size = slots.size();
	for (int i = 0; i < size; i++)
	{
		if (cM.x == 0)
		{
			if (cM.y == 0)
			{
				if (cM.x + 1 == slots[i].first && cM.y + 2 == slots[i].second)
				{
					m.x = slots[i].first;
					m.y = slots[i].second;

					return m;
				}
			}
			
			if (cM.y == 1)
			{
				if (cM.x + 1 == slots[i].first && cM.y + 1 == slots[i].second)
				{
					m.x = slots[i].first;
					m.y = slots[i].second;

					return m;
				}
			}

			if (cM.y > 1)
			{
				if (cM.x + 1 == slots[i].first && (cM.y - 2 == slots[i].second || cM.y - 1 == slots[i].second || cM.y == slots[i].second || cM.y + 1 == slots[i].second || cM.y + 2 == slots[i].second))
				{
					m.x = slots[i].first;
					m.y = slots[i].second;

					return m;
				}
			}
		}
		else
		{
			if(cM.y == 0)
			{
				if ((cM.x - 1 == slots[i].first || cM.x == slots[i].first || cM.x + 1 == slots[i].first) && cM.y + 2 == slots[i].second)
				{
					m.x = slots[i].first;
					m.y = slots[i].second;

					return m;
				}
			}

			if (cM.y == 1)
			{
				if ((cM.x - 1 == slots[i].first || cM.x == slots[i].first || cM.x + 1 == slots[i].first) && cM.y + 1 == slots[i].second)
				{
					m.x = slots[i].first;
					m.y = slots[i].second;

					return m;
				}
			}

			if (cM.y > 1)
			{
				if ((cM.x - 1 == slots[i].first || cM.x == slots[i].first || cM.x + 1 == slots[i].first) && (cM.y - 2 == slots[i].second || cM.y - 1 == slots[i].second || cM.y == slots[i].second || cM.y + 1 == slots[i].second || cM.y + 2 == slots[i].second))
				{
					m.x = slots[i].first;
					m.y = slots[i].second;

					return m;
				}
			}
		}
	}
}

coordMouse clickableSlot(coordMouse cM, std::vector<std::pair<int, int>> slots1, std::vector<std::pair<int, int>> slots2, std::vector<std::pair<int, int>> slots3)
{
	coordMouse m{ 0,0 };	

	m = SlotInProximity(cM, slots1);
	if (m.x != 0 && m.y != 0)
		return m;

	m = SlotInProximity(cM, slots2);
	if (m.x != 0 && m.y != 0)
		return m;

	m = SlotInProximity(cM, slots3);
	if (m.x != 0 && m.y != 0)
		return m;

	return m;
}

coordMouse getCoord(const std::string& action)
{
	coordMouse M;
	int num, num2;
	std::string ex = action;
	size_t pos1 = ex.find("(");
	size_t pos2 = ex.find(",");
	std::string fnum = ex.substr(pos1 + 1, pos2 - pos1 - 1);
	ex.erase(0, pos2 + 2);
	size_t pos3 = ex.find(")");
	ex.erase(pos3);
	num = atoi(fnum.c_str());
	num2 = atoi(ex.c_str());
	M.x = num;
	M.y = num2;

	return M;
}

bool checkClick(const std::string& action)
{
	if (action.find("click") != std::string::npos)
		return true;
	return false;
}

Game::Game()
{
}

Game::~Game()
{
}

void Game::gotoXY(const int& a, const int& b)
{
	COORD coord;
	coord.X = b;
	coord.Y = a;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Game& Game::getGame()
{
	if (!instance)
	{
		instance = new Game();
	}
	return (*instance);
}

void Game::chooseLevel()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);

	std::ifstream logo("levels.txt");
	char* line = new char[256];
	int i = 15;
	while (logo.getline(line, 256))
	{
		conOut(i, 74) << line;
		i++;
	}

	while (1)
	{
		std::string action = conIn.getUserActions();

		if (action != "")
		{
			if (checkClick(action))
			{
				coordMouse M = getCoord(action);

				if (M.x >= 15 && M.x <= 17 && M.y >= 74 && M.y <= 99)
				{
					this->game_level = 1;
					system("cls");
					break;
				}

				if (M.x >= 19 && M.x <= 21 && M.y >= 74 && M.y <= 99)
				{
					this->game_level = 3;
					system("cls");
					break;
				}

				if (M.x >= 23 && M.x <= 25 && M.y >= 74 && M.y <= 99)
				{
					this->game_level = 5;
					system("cls");
					break;
				}
			}
		}
	}

	SetConsoleTextAttribute(hConsole, 7);
	conIn.deleteConIn();
	conOut.deleteConOut();
}

void Game::startGame()
{
	this->chooseLevel();

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	UserInterface::Log logger = UserInterface::Log::getLogger();

	logger.write("The game has started.");
	SetConsole& cons = SetConsole::getInstance();
	Terrain& t = Terrain::getTerrain(this->game_level);
	t.generateTerrain();
	t.setAvailablePlantSlots();
	t.setAvailableSunSlots();
	t.setShopSlots();
	logger.write("Initialize terrain and other elements.");
	coordMouse M = { 0, 0 };
	bool boughtItem = false; // verificam mereu daca avem ceva cumparat inainte de a efectua alta actiune
	bool placedItem = false;
	Player player;
	char ch = ' ';
	auto sunTimer = clock();
	conOut(26, 0) << player.displayShop();
	gotoXY(0, 0);
	int renderCounter = 0;
	bool zombieReady = false;
	bool sunReady = false;
	bool peasReady = false;
	bool bucketHeadReady = false;
	int zombieSpawnTime = 10;
	int bucketHeadSpawnTime = 16;
	int sunSpawnTime = 8;
	int peasSpawnTime = 4;

	while (1)
	{
		std::string action = conIn.getUserActions();
		static auto begin = steady_clock::now();
		auto end = steady_clock::now();
		player.modifyScore(t.returnScore());

		if (!checkGameState(t))
		{
			std::ofstream outfile("players.txt", std::ios_base::app);
			outfile << player.returnScore() << "\n";
			outfile.close();
			this->whoWon = 0;
			logger.write("Game over.");
			gameOver();
			break;
		}

		if (duration_cast<milliseconds>(end - begin).count() > 500)
		{
			begin = end;
			renderCounter++;
			t.entitiesStillAlive();
			t.printEntities();
			zombieReady = sunReady = peasReady = bucketHeadReady = true;
		}
		if (checkWin(t) && renderCounter % 14 == 0 && renderCounter != 0)
		{
			std::ofstream outfile("players.txt", std::ios_base::app);
			outfile << player.returnScore() << "\n";
			outfile.close();
			this->whoWon = 1;
			logger.write("The player has won!");
			gameOver();
			break;
		}
		if (renderCounter % peasSpawnTime == 0 && peasReady)
		{
			t.entityAtacks();
			peasReady = false;
		}
		if (renderCounter % zombieSpawnTime == 0 && zombieReady)
		{
			t.generateZombies();
			zombieReady = false;
			logger.write("A zombie has spawned.");
		}
		if (renderCounter % sunSpawnTime == 0 && sunReady)
		{
			t.generateSuns();
			sunReady = false;
			logger.write("A sun has spawned.");
		}
		if (renderCounter % bucketHeadSpawnTime == 0 && bucketHeadReady)
		{
			t.generateBucketHeadZombies();
			bucketHeadReady = false;
			logger.write("A bucket head zombie has spawned.");
		}
		
		if (t.numberOfSunflowers() != 0)
		{
			if (t.numberOfSunflowers() >= 1 && t.numberOfSunflowers() <= 3)
			{
				sunSpawnTime = 6;
			}
			if (t.numberOfSunflowers() >= 4 && t.numberOfSunflowers() <= 6)
			{
				sunSpawnTime = 4;
			}
			if (t.numberOfSunflowers() >= 7 && t.numberOfSunflowers() <= 9)
			{
				sunSpawnTime = 2;
			}
		}
		else
		{
			sunSpawnTime = 8;
		}

		if (action != "")
		{
			conOut(24, 1) << action; // afiseaza actiunile

			if (checkClick(action))
			{
				M = getCoord(action);
				M = clickableSlot(M, t.checkAvailablePlantSlots(), t.checkUnavailableSunSlots(), t.checkShopSlots());

				if (!boughtItem && M.x == 1 && (M.y == 9 || M.y==16 || M.y==23 || M.y==30 || M.y==37 || M.y==44 || M.y==51||M.y==58||M.y==65))
				{
					conOut(1, M.y) << ' ';
					player.modifyAmountOfMoney(25);
					t.updateSunSlots("delete", M.x, M.y);
					conOut(26, 0) << player.displayShop();
					logger.write("The player has collected a sun");
				}
	
				if (M.y == 2 && (M.x == 5 || M.x == 9 || M.x == 13 /*|| M.x == 17 || M.x == 21*/) && !boughtItem)
				{
					ch = player.buyFromShop(M.x, M.y);
					boughtItem = true;
					gotoXY(26, 0);
					player.hideShop();
					conOut(26, 0) << player.displayShop();
					logger.write("The player has bought an item from the shop");
				}
				if (boughtItem && M.x > 4 && M.y > 6)
				{
					if (ch == 'F')
					{
						Plant* sunflower = new Sunflower(M.x, M.y, 'F');
						t.updatePlantSlots("new", sunflower);
						conOut(M.x, M.y) << 'F';
						ch = ' ';
						boughtItem = false;
						logger.write("The player has spawned a sunflower.");
					}
					if (ch == 'P')
					{
						Plant* peashooter = new Peashooter(M.x, M.y, 'P');
						t.updatePlantSlots("new", peashooter);
						conOut(M.x, M.y) << 'P';
						ch = ' ';
						boughtItem = false;
						logger.write("The player has spawned a peashooter.");
					}
					if (ch == 'W')
					{
						Plant* wallnut = new Wallnut(M.x, M.y, 'W');
						t.updatePlantSlots("new", wallnut);
						conOut(M.x, M.y) << 'W';
						ch = ' ';
						boughtItem = false;
						logger.write("The player has spawned a wallnut.");
					}
					/*if (ch == 'C')
					{
						Plant* cherrybomb = new CherryBomb(M.x, M.y, 'C');
						t.updatePlantSlots("new", cherrybomb);
						conOut(M.x, M.y) << 'C';
						ch = ' ';
						boughtItem = false;
						logger.write("The player has spawned a cherrybomb.");
					}*/
				}
			}
		}
	}

	conIn.deleteConIn();
	conOut.deleteConOut();
}

bool Game::checkGameState(const Terrain& t)
{
	std::vector<Entity*> temp = t.checkEntities();
	int size = temp.size();

	for (int i = 0; i < size; i++)
	{
		if (temp[i]->isMoovable())
		{
			if (temp[i]->posY() == 7)
			{
				return false;
			}
		}
	}

	return true;
}

bool Game::checkWin(const Terrain& t)
{
	std::vector<Entity*> temp = t.checkEntities();
	int size = temp.size();

	for (int i = 0; i < size; i++)
	{
		if (temp[i]->isMoovable())
		{
			return false;
		}
	}

	return true;
}

void Game::gameOver()
{
	system("cls");
}
