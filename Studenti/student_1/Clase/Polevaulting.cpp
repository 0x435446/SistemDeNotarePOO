#include "Polevaulting.h"

using namespace GameMechanics;

Polevaulting::Polevaulting(int rowUp, int colLeft) :Zombie(rowUp, colLeft)
{
	this->ID = EntityID::POLEVAULTING;

	auto index = getIndex(ENEMIES_ID, this->ID);

	this->damage = ENEMIES_DAMAGE[index];
	this->HP = ENEMIES_HP[index];
	this->speed = ENEMIES_SPEED[index];
	this->points = ENEMIES_AWARDED_POINTS[index];
	jumped = false;
}


Polevaulting::~Polevaulting()
{

}

void Polevaulting::move()
{
	if (isColliding && !jumped)
	{
		this->colLeft -= UserInterface::TILE_WIDTH;
		jumped = true;
		isColliding = false;
	}
	else
		Enemy::move();
}

bool GameMechanics::Polevaulting::hasJumped()
{
	return jumped;
}

void GameMechanics::Polevaulting::setJumped(bool b)
{
	this->jumped = b;
}

std::string Polevaulting::serialize()
{
	using namespace std;

	string s = "Polevaulting\n";

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