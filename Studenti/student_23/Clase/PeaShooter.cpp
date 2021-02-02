#include "PeaShooter.h"



PeaShooter::PeaShooter(int X,int Y)
{
	setHealth(100);
	setShootspeed(1);
	setDamage(20);
	setSpecialEffect(0);
	setLook('p');
	setCoords(X, Y);
}

void PeaShooter::setHealth(int viata)
{
	this->health = viata;
}

void PeaShooter::setCost(int pret)
{
	this->cost = pret;
}

void PeaShooter::setShootspeed(int speed)
{
	this->shootspeed = speed;
}

void PeaShooter::setCoords(int X, int Y)
{
	this->coordX = X;
	this->coordY = Y;
}

void PeaShooter::setDamage(int damage)
{
	this->projectileDamage = damage;
}

void PeaShooter::setSpecialEffect(int efect_special)
{
	this->specialEffect = efect_special;
}

void PeaShooter::setLook(char caracter)
{
	this->look = caracter;
}

int PeaShooter::getHealth()
{
	return this->health;
}

int PeaShooter::getCost()
{
	return this->cost;
}

int PeaShooter::getShootSpeed()
{
	return this->shootspeed;
}

int PeaShooter::getX()
{
	return this->coordX;
}

int PeaShooter::getY()
{
	return this->coordY;
}

int PeaShooter::getDamage()
{
	return this->projectileDamage;
}

int PeaShooter::getSpecialEffect()
{
	return this->specialEffect;
}

char PeaShooter::getLook()
{
	return this->look;
}
