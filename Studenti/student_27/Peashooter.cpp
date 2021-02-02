#include "Peashooter.h"

Peashooter::Peashooter()
{
}

Peashooter::~Peashooter()
{
}

Peashooter::Peashooter(char symbol, int cost, int x, int y)
{
	Symbol = symbol;
	pCost = cost;
	xPos = x;
	yPos = y;
}

Peashooter::Peashooter(char symbol, int cost, int x, int y, Projectile* project):Peashooter(symbol,cost,x,y)
{
	projectil = project;
}

int Peashooter::CheckForPeaShooter(int x, int y)
{
	int ok = 0;

	if (xPos == x && yPos == y)
	{
		ok = 1;
	}
	return ok;
}

void Peashooter::Shoot()
{
}

int Peashooter::GetxPos()
{
	return xPos;
}

int Peashooter::GetyPos()
{
	return yPos;
}

char Peashooter::GetSymbol()
{
	return Symbol;
}

Projectile* Peashooter::GetProjectile()
{
	return projectil;
}
