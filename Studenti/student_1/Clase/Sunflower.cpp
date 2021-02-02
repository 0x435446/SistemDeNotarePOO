#include "Sunflower.h"

using namespace GameMechanics;

Sunflower::Sunflower(int rowUp, int colLeft) :Plant(rowUp, colLeft)
{
	this->ID = EntityID::SUNFLOWER;

	auto index = getIndex(PLANTS_ID, this->ID);

	this->HP = PLANTS_HP[index];
	this->cost = PLANTS_COST[index];
	this->width = UserInterface::SUNFLOWER_WIDTH;
}


Sunflower::~Sunflower()
{
}


std::string Sunflower::serialize()
{
	using namespace std;

	string s = "Sunflower\n";

	s += to_string(this->rowUp);
	s += " ";
	s += to_string(this->colLeft);
	s += " ";
	s += to_string(this->HP);
	s += "\n";

	return s;
}