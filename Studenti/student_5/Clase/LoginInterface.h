#pragma once
#include "ConsoleOutput.h"
class LoginInterface
{
public:
	LoginInterface();
	~LoginInterface();

	static void start(UserInterface::ConsoleOutput conOut, std::string &user);
	static void endGame(UserInterface::ConsoleOutput conOut, bool gameOver, bool win, int scor);
};

