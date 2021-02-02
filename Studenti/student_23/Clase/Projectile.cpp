#include "Projectile.h"

Projectile::Projectile(int x, int y, int daune, int efect_special, char caracter)
{
	this->damage = daune;
	this->special_effect = efect_special;
	this->look = caracter;
	this->X = x;
	this->Y = y;
}


int Projectile::getDamage()
{
	return damage;
}

int Projectile::getSpecialEffect()
{
	return special_effect;
}

char Projectile::getLook()
{
	return look;
}

void Projectile::getCoords(int& x, int& y)
{
	x = this->X;
	y = this->Y;
}

void Projectile::updateX()
{
	this->X = X + 1;
}
