#pragma once
#include "ConsoleOutput.h"
class Score
{
public:
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	int scor;
	Score();
	void setscore(int val);
	void printScor();
	~Score();
};

