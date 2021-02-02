#pragma once
#include"ConsoleInput.h"
#include"ConsoleOutput.h"
class score
{
	int scor;
public:
	score();
	~score();
	void setscore(int);
	void printScor();
private:
	
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();


};

