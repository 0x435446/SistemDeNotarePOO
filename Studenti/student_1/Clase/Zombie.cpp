#include "Zombie.h"

using namespace GameMechanics;

Zombie::Zombie(int rowUp, int colLeft) :Enemy(rowUp, colLeft)
{
	this->ID = EntityID::ZOMBIE;

	auto index = getIndex(ENEMIES_ID, this->ID);

	this->damage = ENEMIES_DAMAGE[index];
	this->HP = ENEMIES_HP[index];
	this->speed = ENEMIES_SPEED[index];
	this->width = UserInterface::ZOMBIE_WIDTH;
	this->points = ENEMIES_AWARDED_POINTS[index];
}


Zombie::~Zombie()
{
}

bool GameMechanics::Zombie::hasJumped()
{
	return false;
}

void GameMechanics::Zombie::setJumped(bool)
{
	return;
}

std::string Zombie::serialize()
{
	using namespace std;

	string s = "Zombie\n";

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
