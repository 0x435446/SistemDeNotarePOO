#include "BucketHead_Zombie.h"

BucketHead_Zombie::BucketHead_Zombie()
{
}

BucketHead_Zombie::~BucketHead_Zombie()
{
}

BucketHead_Zombie::BucketHead_Zombie(int speed, int health, char symbol) :Zombie(speed, health, symbol)
{
}

void BucketHead_Zombie::SetxPos(int x)
{
	xPos = x;
}

void BucketHead_Zombie::SetyPos(int y)
{
	yPos = y;
}

int BucketHead_Zombie::GetxPos()
{
	return xPos;
}

int BucketHead_Zombie::GetyPos()
{
	return yPos;
}

int BucketHead_Zombie::GetSpeed()
{
	return Speed;
}

int BucketHead_Zombie::GetHealth()
{
	return Health;
}

void BucketHead_Zombie::ReduceHealth(int reduce)
{
	Health = Health - reduce;
}

char BucketHead_Zombie::GetSymbol()
{
	return Symbol;
}
