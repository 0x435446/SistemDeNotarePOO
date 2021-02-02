#pragma once
#include <fstream>
#include "Game.h"

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5

class Menu final
{
	static Menu* instance;
	Menu();
	Menu(const Menu&);

	std::string playerName = " ";

public:
	static Menu& getMenu();

	void printLogo();
	void printGameOver();
	void printPlayerWon();

	void initializeGame();

	void loadingMenu();
	void doLoadingMenuBar();
	~Menu();
};

