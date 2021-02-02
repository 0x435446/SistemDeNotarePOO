#include "BattleTile.h"
BattleTile::BattleTile(int sX, int sY)
{
	this->startX = sX;
	this->startY = sY;
	this->plant = nullptr;
	this->occupied = false;
}
void BattleTile::draw() 
{
	if (this->occupied)
	{
		this->plant->executeFunction();
	}
}
bool BattleTile::pressedInside(int x, int y)
{
	if ((x >= this->startX && x <= this->startX + TILE_HEIGHT) && (y >= this->startY && y <= this->startY + TILE_WIDTH))
	{
		return true;
	}
	return false;
}
bool BattleTile::getSuns(int x,int y)
{
	if (this->plant)
	{
		if (this->plant->getName() == "Sunflower")
		{
			if (this->plant->getSuns())
			{
				this->plant->reduceSuns();
				return true;
			}
		}
	}
	return false;
}