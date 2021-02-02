#include "Sunflower.h"

int Sunflower::counter = 0;

Sunflower::Sunflower(const unsigned int& posX, const unsigned int& posY, char c) : Plant(posX, posY, c)
{
	counter++;
}

void Sunflower::attack()
{
}


Sunflower::~Sunflower()
{
	counter--;
}
