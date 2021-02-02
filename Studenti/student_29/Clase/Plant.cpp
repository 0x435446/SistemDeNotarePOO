#include "Plant.h"



Plant::Plant(const unsigned int& posX, const unsigned int& posY, char c) : Entity(posX, posY, c)
{
	movable = false;
	life = 10;
	dmg = 0;
	hasNormalPeas = false;
}

void Plant::move()
{

}

Plant::~Plant()
{
}
