#include "Missile.h"
#define base_specialEfect 1


Missile::Missile(int pozX, int pozY, bool isMoving, short int movement) 
	: Entity(pozX, pozY, isMoving, movement)
{

	this->specialEfect = base_specialEfect;
}


Missile::~Missile()
{
}

float Missile::getSpecial()
{
	return this->specialEfect;
}

void Missile::specialSetPozX(float pozX)
{
	this->pozX = pozX;
	this->lastPozX = 0;
	this->lastPozY = 0;
}

void Missile::specialSetPozY(float pozY)
{
	this->pozY = pozY;
}


