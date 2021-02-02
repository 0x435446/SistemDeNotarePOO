#include "Peashooter.h"



Peashooter::Peashooter(const unsigned int& posX, const unsigned int& posY, char c) : Plant(posX, posY, c)
{
	hasNormalPeas = true;
}

void Peashooter::attack()
{

}

Pea& Peashooter::attackZombie()
{
	Pea* pea = new Pea(this->posX(), this->posY());
	
	return *pea;
}

Peashooter::~Peashooter()
{
}
