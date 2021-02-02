#include "Plants.h"



Plants::Plants()
{
}

Plants::Plants(const int health, const std::string name)
{
	this->health = health;
	this->name = name;
	this->shootTime = 5000;
}

Plants::Plants(const int health, const std::string name, const int shootTime)
{
	this->health = health;
	this->name = name;
	this->shootTime = shootTime;
}

void Plants::setXY(const int x, const int y)
{
	this->x = x;
	this->y = y;
}



const int Plants::getDamage()
{
	return 0;
}

void Plants::takeDamage(const int damageValue)
{
	this->health -= damageValue;
}

Plants::~Plants()
{
}
