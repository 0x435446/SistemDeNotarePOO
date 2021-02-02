#pragma once
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <algorithm>
#include <vector>
#include <list>
#include <chrono>
#include <map>
#include <fstream>
#include <cmath>
#include <random>
#include "Map.h"
#include "Sun.h"
#include "Action.h"
#include "PlantPeaShooter.h"
#include "ShopPlants.h"
#include "PlantSunflower.h"
#include "PlantWallNut.h"
#include "PlantCherryBomb.h"
#include "PlantFrozenPea.h"
#include "Zombie.h"
#include "BucketHeadZombie.h"
#include "PoleVaultingZombie.h"
#include "SuperZombie.h"
#include "PeaProjectile.h"
#include "FrozenPeaProjectile.h"
#include <list>

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5

using namespace std::chrono;


class Game
{
private:
	static Game* instance;
	Game();
	Game(Game* other);
	~Game();
public:
	static Game& getInstance();
	static void spawnSuns();
	static void plant(Action A, int &toPlant);
	static void verifySelection(Action A, int &toPlant);
	static void drawProjectiles();
	static void drawShop();
	static void combat();
	static void levels();
	static void checkWin();
	static void screenEntry();
	static void mainMenu();
	static void newGame();
	static void loadGame();
	static void readPlayersList();
	static void save(Action A);
	static void clearScreen();
	static void gameOver();
	static void writePlayers();
	static void showHighscores();
	void deleteInstance();
};

