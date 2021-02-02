#include "Sun.h"
#include "Score.h"
#include "ConsoleOutput.h"


Sun::Sun(int x, int y)
{
	this->x = x;
	this->y = y;
	this->set = false;
}

void Sun::print()
{
	conOut(y-2 , x+5 ) << "Sun";
	this->set = true;		
}

void Sun::erase()
{
	conOut(y - 2, x + 5) << "   ";
	this->set = false;
}

Sun::~Sun()
{
}
