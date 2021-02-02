#include "Buckethead.h"

using namespace GameMechanics;

Buckethead::Buckethead(int rowUp, int colLeft):Zombie(rowUp, colLeft)
{
	this->ID = EntityID::BUCKETHEAD;

	auto index = getIndex(ENEMIES_ID, this->ID);

	this->damage = ENEMIES_DAMAGE[index];
	this->HP = ENEMIES_HP[index];
	this->speed = ENEMIES_SPEED[index];
	this->points = ENEMIES_AWARDED_POINTS[index];
}


Buckethead::~Buckethead()
{
}

std::string Buckethead::serialize()
{
	using namespace std;

	string s = "Buckethead\n";

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
	s += "\n";

	return s;
}