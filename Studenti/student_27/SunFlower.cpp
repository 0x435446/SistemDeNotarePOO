#include "SunFlower.h"

SunFlower::SunFlower()
{
}

SunFlower::~SunFlower()
{
}

SunFlower::SunFlower(char symbol, int cost)
{
	Symbol = symbol;
	pCost = cost;
}

SunFlower::SunFlower(char symbol, int cost, int x, int y):SunFlower(symbol,cost)
{
	xPos = x;
	yPos = y;
}

int SunFlower::CheckForSunFlower(int x, int y)
{
	int ok = 0;

	if (xPos == x && yPos == y)
	{
		ok = 1;
	}
	return ok;
}

int SunFlower::GetxPos()
{
	return xPos;
}

int SunFlower::GetyPos()
{
	return yPos;
}

char SunFlower::GetSymbol()
{
	return Symbol;
}
