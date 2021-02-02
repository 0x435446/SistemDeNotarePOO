#include "NormalZombie.h"


NormalZombie::NormalZombie(const unsigned int& posX, const unsigned int& posY, char c) : Zombie(posX, posY, c)
{
	move_speed = 1;
}

void NormalZombie::attack()
{
}

NormalZombie::~NormalZombie()
{
}
