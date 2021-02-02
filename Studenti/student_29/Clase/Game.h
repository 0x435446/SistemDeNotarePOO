#pragma once

#include <time.h>
#include <chrono>
#include <thread>
#include <iostream>

#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Terrain.h"


class Game final
{
	static Game* instance;

	int game_level;
	int whoWon;

	Game();
	Game(const Game&);
	~Game();
public:
	static Game& getGame();
	void chooseLevel();
	void startGame();
	bool checkGameState(const Terrain& t);
	bool checkWin(const Terrain& t);
	void gameOver();
	void gotoXY(const int&, const int&);
	int returnWhoWon() const { return whoWon; };
};

