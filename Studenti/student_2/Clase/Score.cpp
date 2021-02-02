#include "Score.h"



Score::Score()
{
	scor = 0;
	printScor();
}

void Score::setscore(int val)
{
	scor += val;
}


void Score::printScor()
{
	conOut(1, 4) << "SCORE";
	conOut(2, 4) << scor;
}

Score::~Score()
{
}
