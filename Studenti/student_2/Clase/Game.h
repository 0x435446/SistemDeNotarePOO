#pragma once
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Zombi.h"
#include <chrono>
#include <vector>
class Game
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput &conIn = UserInterface::ConsoleInput::getInstance();
public:
	Game();
	std::vector<Zombie*> monster;
	void doLoadingBar();
	void play();
	~Game();
	void move_zom();
};

