#include "score.h"
#include"ConsoleInput.h"
#include"ConsoleOutput.h"
score::score()
{
	scor = 0;
	printScor();
}

void score::setscore(int val)
{
	scor += val;
}


void score::printScor()
{
	conOut(4,1) << "SCORE";
	conOut(4,2) << scor;
}

score::~score()
{
}