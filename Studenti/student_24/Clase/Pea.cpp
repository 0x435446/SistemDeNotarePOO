#pragma once
#include "Pea.h"
#include "ConsoleOutput.h"
#include "Map.h"

int Pea::getx()
{
	return x;
}

int Pea::gety()
{
	return y;
}

void Pea::setlife(int x)
{
	life = x;

}

int Pea::getlife()
{
	return life;
}

Pea::Pea(int a, int b)
{
	life = 1;
	damage = 1;
	x = a;
	y = b;
	draw();
	y++;
}



void Pea::uppdate(std::string action)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y - 1) << " ";
	conOut(x, y) << "@";
	y++;
	for (int i = 0; i < Map::zombie.size(); i++)
		if (x == Map::zombie[i]->getx() && y == Map::zombie[i]->gety())
		{
			life = 0;
			Map::zombie[i]->lifeminus(damage);
		}
	
}

void Pea::draw()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y) << "@";


}

Pea::Pea()
{
}


Pea::~Pea()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(x, y-1) << " ";

}
