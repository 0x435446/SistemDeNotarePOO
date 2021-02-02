#pragma once
#include "ConsoleOutput.h"
class Plant
{
protected:
	int x;
	int y;
	bool set;

public:
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	Plant();
	Plant(int x, int y);
	virtual void print(int x, int y);
	
	virtual ~Plant();
	
};

