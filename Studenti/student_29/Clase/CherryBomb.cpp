#include "CherryBomb.h"


CherryBomb::CherryBomb(const unsigned int& posX, const unsigned int& posY, char c) : Plant(posX, posY, c)
{
	dmg = 10;
}

void CherryBomb::attack()
{
}

CherryBomb::~CherryBomb()
{
}
