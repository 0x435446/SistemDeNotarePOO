#pragma once
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Score.h"
class Sun
{
public:

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	int x, y;
	Sun(int x,int y);
	bool set;
	void print();
	void erase();


	~Sun();
};

