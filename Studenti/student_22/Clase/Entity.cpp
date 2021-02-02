#include "Entity.h"
#define base_movingSpeed 1

Entity::Entity()
{
}

Entity::Entity(float pozX, float pozY, bool isMoving, short int movement)
{
	this->pozX = pozX;
	this->pozY = pozY;
	this->lastPozX = pozX;
	this->lastPozY = pozY;
	this->isMoving = isMoving;
	this->movement = movement;
	this->isDead = false;
	this->movingSpeed = base_movingSpeed;
}

Entity::~Entity()
{
}

float Entity::getPozX()
{
	return this->pozX;
}

float Entity::getPozY()
{
	return this->pozY;
}

float Entity::getLastPozX()
{
	return this->lastPozX;
}

float Entity::getLastPozY()
{
	return this->lastPozY;
}

short int Entity::getMovement()
{
	return this->movement;
}

bool Entity::getIsMoving()
{
	return this->isMoving;
}

bool Entity::getIsDead()
{
	return this->isDead;
}

void Entity::setIsMoving(bool bo)
{
	this->isMoving = bo;
}

void Entity::setIsDead(bool isDead)
{
	this->isDead = isDead;
}

void Entity::setPozX(float pozX)
{
	this->lastPozX = this->pozX;
	this->pozX = pozX;
}

void Entity::setPozY(float pozY)
{
	this->lastPozY = this->pozY;
	this->pozY = pozY;
}

std::string Entity::getTag()
{
	return this->tag;
}

void Entity::setTag(std::string tag)
{
	this->tag = tag;
}

double Entity::getMovingSpeed()
{
	return this->movingSpeed;
}
