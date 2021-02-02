#pragma once
#include <time.h>
#include <chrono>
#include <vector>
#include <map>
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
class Map
{
public:
	Map();
	void doLoadingBar();
	void clearScreen();
	void gameOver();
	void drawSunshine(int nr);
	void deleteSunshine(int nr);
	void drawTiles(int level,int score);
	int drawPlant(int X,int Y,char character);
	void drawZombie(int X,int Y,char character);
	void drawProjectile(int X, int Y,char caracter);
	void userAction();
	int checkCoords(int X, int Y);
	void updateMoney(int bani);

	int testField(int X, int Y);
	void tester(std::string test);

private:
	std::map<char,int> linie;
	UserInterface::ConsoleOutput conOut;
	UserInterface::ConsoleInput conIn;
	char field[40][150];
};

