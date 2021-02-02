#include "BucketHead.h"

BucketHead::BucketHead(int X, int Y)
{
	setHealth(240);
	setSpeed(5);
	setAttack(25);
	setCoords(X, Y);
	setSpecialEffect(0);
	setLook('b');
}

void BucketHead::setHealth(int viata)
{
	this->health = viata;
}

void BucketHead::setSpeed(int speed)
{
	this->speed = speed;
}

void BucketHead::setAttack(int damage)
{
	this->attack = damage;
}

void BucketHead::setCoords(int X, int Y)
{
	this->coordX = X;
	this->coordY = Y;
}

void BucketHead::setSpecialEffect(int efect_special)
{
	this->specialEffect = efect_special;
}

void BucketHead::setLook(char caracter)
{
	this->look = caracter;
}

int BucketHead::getHealth()
{
	return health;
}

int BucketHead::getSpeed()
{
	return speed;
}

int BucketHead::getDamage()
{
	return attack;
}

int BucketHead::getX()
{
	return coordX;
}

int BucketHead::getY()
{
	return coordY;
}

int BucketHead::getSpecialEffect()
{
	return specialEffect;
}

char BucketHead::getLook()
{
	return look;
}
