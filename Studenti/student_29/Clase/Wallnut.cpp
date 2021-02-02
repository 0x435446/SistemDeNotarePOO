#include "Wallnut.h"



Wallnut::Wallnut(const unsigned int& posX, const unsigned int& posY, char c) : Plant(posX, posY, c)
{
	this->hasNormalPeas = false;
	this->life = 22;
}

void Wallnut::attack()
{
}


Wallnut::~Wallnut()
{
}
