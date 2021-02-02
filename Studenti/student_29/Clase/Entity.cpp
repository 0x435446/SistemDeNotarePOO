#include "Entity.h"


Entity::Entity(const unsigned int& posX, const unsigned int& posY, char c) : x(posX), y(posY), ch(c)
{
}

char Entity::showSymbol()
{
	return ch;
}

bool Entity::isAlive()
{
	if (this->life > 0)
		return true;
	return false;
}

void Entity::damage(const double& dmg)
{
	this->life -= dmg;
}

Entity::~Entity()
{
}
