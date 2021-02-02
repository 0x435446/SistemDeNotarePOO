#include "Entity.h"

std::ofstream outFile;


Entity::Entity(int x, int y, std::string glyph) : x(x), y(y), glyph(glyph)
{
	outFile.open("debug.log", std::ios::app);
	actionTimer = std::chrono::system_clock::now();
	special = false;
}

Entity::~Entity()
{
}

int Entity::getX()
{
	return this->x;
}

int Entity::getY()
{
	return this->y;
}

std::string Entity::getGlyph()
{
	return this->glyph;
}

void Entity::setX(int x)
{
	this->x = x;
}

void Entity::setY(int y)
{
	this->y = y;
}

void Entity::setGlyph(std::string glyph)
{
	this->glyph = glyph;
}

std::chrono::time_point<std::chrono::system_clock> Entity::getTimer()
{
	return actionTimer;
}

void Entity::setTimer(std::chrono::time_point<std::chrono::system_clock> timer)
{
	actionTimer = timer;
}

int Entity::getMovement()
{
	return movement;
}

bool Entity::getSpecial()
{
	return special;
}
