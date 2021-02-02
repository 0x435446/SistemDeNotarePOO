#include "CherryBomb.h"

using namespace GameMechanics;

CherryBomb::CherryBomb(int rowUp, int colLeft): Plant(rowUp, colLeft)
{
	this->ID = EntityID::CHERRYBOMB;

	auto index = getIndex(PLANTS_ID, this->ID);

	this->HP = PLANTS_HP[index];
	this->cost = PLANTS_COST[index];
	this->width = UserInterface::CHERRYBOMB_WIDTH;

	this->projectileType = EntityID::EXPLOSION;
	this->shootRate = PLANTS_SHOOTING_RATE[index];
}


CherryBomb::~CherryBomb()
{
}

std::string CherryBomb::serialize()
{
	using namespace std;

	string s = "CherryBomb\n";

	s += to_string(this->rowUp);
	s += " ";
	s += to_string(this->colLeft);
	s += " ";
	s += to_string(this->HP);
	s += "\n";

	return s;
}