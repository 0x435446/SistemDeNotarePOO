#include "Zombie.h"



Zombie::Zombie(const unsigned int& posX, const unsigned int& posY, char c) : Entity(posX, posY, c)
{
	movable = true;
	life = 10;
	dmg = 3.4;
	hasNormalPeas = false;
}

void Zombie::move()
{
	this->y -= move_speed;
}

Zombie::~Zombie()
{
}
