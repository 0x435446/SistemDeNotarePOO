#include "Plant.h"

using namespace GameMechanics;

Plant::Plant(int rowUp, int colLeft) : Entity(rowUp, colLeft)
{
}


Plant::~Plant()
{
}

EntityID GameMechanics::Plant::shoot()
{
	return projectileType;
}

int GameMechanics::Plant::getShootRate()
{
	return shootRate;
}
