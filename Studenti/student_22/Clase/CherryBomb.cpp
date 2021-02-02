#include "CherryBomb.h"
#define special_comeBackAttack 3


CherryBomb::CherryBomb(int pozX, int pozY):Plant(pozX, pozY)
{
	this->health = 1;
	this->comeBackAttak = special_comeBackAttack;
}


CherryBomb::~CherryBomb()
{
}

std::string CherryBomb::getAttackingType()
{
	return "bomb";
}
