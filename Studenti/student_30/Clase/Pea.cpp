#include "Pea.h"



Pea::Pea()
{
}

Pea::Pea(int a, int b)
{
	x = a;
	y = b;
}

Pea::~Pea()
{
}


void Pea::move()
{
	UserInterface::ConsoleOutput out = UserInterface::ConsoleOutput::getInstance();
	out(x, y - 1) << " ";
	out(x, y) << "O";
	y++;
}