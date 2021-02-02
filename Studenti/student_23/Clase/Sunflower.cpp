#include "Sunflower.h"

Sunflower::Sunflower(int X, int Y)
{
	setHealth(100);
	setShootspeed(0);
	setDamage(0);
	setSpecialEffect(1);
	setLook('s');
	setCoords(X, Y);
}

void Sunflower::setHealth(int viata)
{
	this->health = viata;
}

void Sunflower::setCost(int pret)
{
	this->cost = pret;
}

void Sunflower::setShootspeed(int speed)
{
	this->shootspeed = speed;
}

void Sunflower::setCoords(int X, int Y)
{
	this->coordX = X;
	this->coordY = Y;
}

void Sunflower::setDamage(int damage)
{
	this->projectileDamage = damage;
}

void Sunflower::setSpecialEffect(int efect_special)
{
	this->specialEffect = efect_special;
}

void Sunflower::setLook(char caracter)
{
	this->look = caracter;
}

int Sunflower::getHealth()
{
	return this->health;
}

int Sunflower::getCost()
{
	return this->cost;
}

int Sunflower::getShootSpeed()
{
	return this->shootspeed;
}

int Sunflower::getX()
{
	return this->coordX;
}

int Sunflower::getY()
{
	return this->coordY;
}

int Sunflower::getDamage()
{
	return this->projectileDamage;
}

int Sunflower::getSpecialEffect()
{
	return this->specialEffect;
}

char Sunflower::getLook()
{
	return this->look;
}

