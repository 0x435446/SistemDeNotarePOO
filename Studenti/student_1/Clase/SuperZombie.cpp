#include "SuperZombie.h"

using namespace GameMechanics;

SuperZombie::SuperZombie(int rowUp, int colLeft) :Zombie(rowUp, colLeft), Polevaulting(rowUp, colLeft), Buckethead(rowUp, colLeft)
{
	this->ID = EntityID::SUPERZOMBIE;

	auto index = getIndex(ENEMIES_ID, this->ID);

	this->damage = ENEMIES_DAMAGE[index];
	this->HP = ENEMIES_HP[index];
	this->speed = ENEMIES_SPEED[index];
	this->points = ENEMIES_AWARDED_POINTS[index];
}

SuperZombie::~SuperZombie()
{
}

std::string SuperZombie::serialize()
{
	using namespace std;

	string s = "SuperZombie\n";

	s += to_string(this->rowUp);
	s += " ";
	s += to_string(this->colLeft);
	s += " ";
	s += to_string(this->HP);
	s += " ";
	auto index = getIndex(EFFECTS, this->effect);
	s += to_string(index);
	s += " ";
	s += to_string(this->timeInflicted);
	s += " ";
	s += to_string(this->isColliding);
	s += " ";
	s += to_string(this->jumped);
	s += "\n";

	return s;
}

