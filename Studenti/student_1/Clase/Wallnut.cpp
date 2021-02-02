#include "Wallnut.h"

using namespace GameMechanics;

Wallnut::Wallnut(int rowUp, int colLeft) : Plant(rowUp, colLeft)
{
	this->ID = EntityID::WALLNUT;

	auto index = getIndex(PLANTS_ID, this->ID);

	this->HP = PLANTS_HP[index];
	this->cost = PLANTS_COST[index];
	this->width = UserInterface::WALLNUT_WIDTH;
}


Wallnut::~Wallnut()
{
}


std::string Wallnut::serialize()
{
	using namespace std;

	string s = "Wallnut\n";

	s += to_string(this->rowUp);
	s += " ";
	s += to_string(this->colLeft);
	s += " ";
	s += to_string(this->HP);
	s += "\n";

	return s;
}