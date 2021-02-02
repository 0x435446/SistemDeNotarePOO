#include "NormalZombie.h"

NormalZombie::NormalZombie(int X,int Y)
{
	setHealth(120);
	setSpeed(2);
	setAttack(25);
	setCoords(X, Y);
	setSpecialEffect(0);
	setLook('z');
}

void NormalZombie::setHealth(int viata)
{
	this->health = viata;
}

void NormalZombie::setSpeed(int speed)
{
	this->speed = speed;
}

void NormalZombie::setAttack(int damage)
{
	this->attack = damage;
}

void NormalZombie::setCoords(int X, int Y)
{
	this->coordX = X;
	this->coordY = Y;
}

void NormalZombie::setSpecialEffect(int efect_special)
{
	this->specialEffect = efect_special;
}

void NormalZombie::setLook(char caracter)
{
	this->look = caracter;
}

int NormalZombie::getHealth()
{
	return health;
}

int NormalZombie::getSpeed()
{
	return speed;
}

int NormalZombie::getDamage()
{
	return attack;
}

int NormalZombie::getX()
{
	return coordX;
}

int NormalZombie::getY()
{
	return coordY;
}

int NormalZombie::getSpecialEffect()
{
	return specialEffect;
}

char NormalZombie::getLook()
{
	return look;
}

