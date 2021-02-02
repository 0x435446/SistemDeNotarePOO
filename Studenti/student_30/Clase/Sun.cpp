#include "Sun.h"
#include "ConsoleOutput.h"
#include<iostream>

using namespace std;

Sun::Sun():Resurse()
{

}

Sun::Sun(int x, int y)
{
	this->x = x;
	this->y = y;
	valoare_sun = 25;
}


Sun::~Sun()
{
}


void Sun::draw()
{
	UserInterface::ConsoleOutput out = UserInterface::ConsoleOutput::getInstance();
	out(x, y) << "\-";
	out(x + 1, y - 1) << "-";
	out(x + 1, y) << "o";
	out(x + 1, y + 1) << "\-";
	out(x + 2, y) << "\-";
}