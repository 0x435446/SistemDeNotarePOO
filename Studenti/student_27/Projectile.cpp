#include "Projectile.h"

Projectile::Projectile()
{
}

Projectile::~Projectile()
{
}

Projectile::Projectile(char symbol)
{
	Symbol = symbol;
}

Projectile::Projectile(char symbol, int x, int y,int damage):Projectile(symbol)
{
	xPos = x;
	yPos = y;
	Damage = damage;
}

char Projectile::GetSymbol()
{
	return Symbol;
}

int Projectile::GetxPos()
{
	return xPos;
}

int Projectile::GetyPos()
{
	return yPos;
}

void Projectile::SetyPos()
{
	yPos = yPos + 1;
}

void Projectile::SetyPos(int y)
{
	yPos = y;
}

int Projectile::GetDamage()
{
	return Damage;
}
