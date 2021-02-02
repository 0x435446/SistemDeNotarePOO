#include "WallNut.h"
#define base_health 4


WallNut::WallNut(int pozX, int pozY):Plant(pozX, pozY)
{
	this->health = base_health;
}


WallNut::~WallNut()
{
}

float WallNut::getHealth()
{
	return this->health;
}

std::string WallNut::getAttackingType()
{
	return "none";
}
