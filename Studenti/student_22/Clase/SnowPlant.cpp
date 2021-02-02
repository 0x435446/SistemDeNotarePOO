#include "SnowPlant.h"



SnowPlant::SnowPlant(int pozX, int pozY):Plant(pozX, pozY)
{
}

std::string SnowPlant::getAttackingType()
{
	return "snow";
}


SnowPlant::~SnowPlant()
{
}

