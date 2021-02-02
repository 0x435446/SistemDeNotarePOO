#pragma once
#include "ConsoleOutput.h"
#include "vector"
#include <chrono>
#include "Entity.h"
#include <fstream>

class Game
{
public:
	Game(UserInterface::ConsoleOutput conOut);
	~Game();
	void start();
	void update(std::pair<int, int> mousePoz, bool hasDoubleClicked);
	void sunSpawn(std::chrono::time_point<std::chrono::system_clock> &time);
	void plantSpawn(std::chrono::time_point<std::chrono::system_clock> &time);
	void zombieSpawn(std::chrono::time_point<std::chrono::system_clock> &time);
	bool getGameOver();
	bool getWin();
	int getScor();
	void gameClear();
private:
	std::vector<Entity *> sunList;
	std::vector<Entity *> plantList;
	std::vector<Entity*> peaList;
	std::vector<Entity*> draw;
	Entity *selectedPlant;
	std::vector<Entity*> arenaPlants;
	std::vector<Entity*> zombieList;
	bool isSelected;
	std::chrono::time_point<std::chrono::steady_clock> drawTime;
	int zombie_counter;
	int sunCounter;
	float sunSpawnTimer;
	int scor;
	std::ofstream outLog;
	bool gameOver;
	bool win;
	UserInterface::ConsoleOutput conOut;
};

