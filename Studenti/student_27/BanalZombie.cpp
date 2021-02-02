#include "BanalZombie.h"

BanalZombie::BanalZombie()
{
}

BanalZombie::~BanalZombie()
{
}

BanalZombie::BanalZombie(int speed, int health,char symbol):Zombie(speed,health,symbol)
{
}

void BanalZombie::SetxPos(int x)
{
	xPos = x;
}

void BanalZombie::SetyPos(int y)
{
	yPos = y;
}

int BanalZombie::GetxPos()
{
	return xPos;
}

int BanalZombie::GetyPos()
{
	return yPos;
}

int BanalZombie::GetSpeed()
{
	return Speed;
}

int BanalZombie::GetHealth()
{
	return Health;
}

void BanalZombie::ReduceHealth(int reduce)
{
	Health = Health - reduce;
}

char BanalZombie::GetSymbol()
{
	return Symbol;
}


