#include "AvatarTile.h"
AvatarTile::AvatarTile(int sX, int sY)
{
	this->startX = sX;
	this->startY = sY;
	this->occupied = false;
	this->plant = nullptr;
}
void AvatarTile::draw()
{
	if (!occupied)
	{
		UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
		for (int j = 0; j < 5; ++j)
		{
			conOut(this->startX + j, this->startY) << "                   ";
		}
	}
	else
	{
		this->plant->draw();
	}
}