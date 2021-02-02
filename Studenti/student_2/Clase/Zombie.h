#pragma once
#include "ConsoleOutput.h"
class Zombie
{protected:
	int x;
	int y;
public:
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	Zombie();
	Zombie(int x, int y);
	virtual void print(int x, int y);
	void erase();
	void move();
	
	virtual ~Zombie();
};

