#include "WallNut.h"


WallNut::WallNut(int X, int Y)
{
	setHealth(500);
	setShootspeed(0);
	setDamage(0);
	setSpecialEffect(0);
	setLook('w');
	setCoords(X, Y);
}

void WallNut::setHealth(int viata)
{
	this->health = viata;
}

void WallNut::setCost(int pret)
{
	this->cost = pret;
}

void WallNut::setShootspeed(int speed)
{
	this->shootspeed = speed;
}

void WallNut::setCoords(int X, int Y)
{
	this->coordX = X;
	this->coordY = Y;
}

void WallNut::setDamage(int damage)
{
	this->projectileDamage = damage;
}

void WallNut::setSpecialEffect(int efect_special)
{
	this->specialEffect = efect_special;
}

void WallNut::setLook(char caracter)
{
	this->look = caracter;
}

int WallNut::getHealth()
{
	return this->health;
}

int WallNut::getCost()
{
	return this->cost;
}

int WallNut::getShootSpeed()
{
	return this->shootspeed;
}

int WallNut::getX()
{
	return this->coordX;
}

int WallNut::getY()
{
	return this->coordY;
}

int WallNut::getDamage()
{
	return this->projectileDamage;
}

int WallNut::getSpecialEffect()
{
	return this->specialEffect;
}

char WallNut::getLook()
{
	return this->look;
}

