#include "SnowPea.h"

using namespace GameMechanics;

SnowPea::SnowPea(int rowUp, int colLeft): Peashooter(rowUp, colLeft)
{
	this->ID = EntityID::SNOWPEA;

	auto index = getIndex(PLANTS_ID, this->ID);

	this->HP = PLANTS_HP[index];
	this->cost = PLANTS_COST[index];

	this->projectileType = EntityID::FROZENPEA;
}


SnowPea::~SnowPea()
{
}

std::string SnowPea::serialize()
{
	using namespace std;

	string s = "SnowPea\n";

	s += to_string(this->rowUp);
	s += " ";
	s += to_string(this->colLeft);
	s += " ";
	s += to_string(this->HP);
	s += "\n";

	return s;
}
