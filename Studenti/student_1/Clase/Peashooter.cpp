#include "Peashooter.h"
#include "Projectile.h"

using namespace GameMechanics;

Peashooter::Peashooter(int rowUp, int colLeft) : Plant(rowUp, colLeft)
{
	this->ID = EntityID::PEASHOOTER;

	auto index = getIndex(PLANTS_ID, this->ID);

	this->HP = PLANTS_HP[index];
	this->cost = PLANTS_COST[index];
	this->width = UserInterface::PEASHOOTER_WIDTH;

	this->projectileType = EntityID::PEA;
	this->shootRate = PLANTS_SHOOTING_RATE[index];
}


Peashooter::~Peashooter()
{
}

std::string Peashooter::serialize()
{
	using namespace std;

	string s = "Peashooter\n";

	s += to_string(this->rowUp);
	s += " ";
	s += to_string(this->colLeft);
	s += " ";
	s += to_string(this->HP);
	s += "\n";

	return s;
}