#pragma once
#include "MenuTile.h"
#include <vector>
#include <string>
using namespace std;
#define DISTANCE_BETWEEN_TILES 5
class Menu
{
public:
	Menu(int, int, int);
	void addOption(std::string, int, int);
	void drawMenu();
	void hideMenu();
	bool existentOption(std::string);
	std::string buttonPressed(std::string);
private:
	vector<MenuTile*> menuBar;
	int menuX, menuY;
	int no_of_tiles;
};

