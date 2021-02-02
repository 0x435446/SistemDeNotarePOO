#include "ResourceGrid.h"
ResourceGrid* ResourceGrid::instance = nullptr;
ResourceGrid::ResourceGrid()
{
	this->begin = steady_clock::now();
	this->startX = 0;
	this->startY = 20;
	this->money = 0;
}
ResourceGrid& ResourceGrid::getInstance()
{
	if (!ResourceGrid::instance)
	{
		ResourceGrid::instance = new ResourceGrid;
	}
	return *ResourceGrid::instance;
}
void ResourceGrid::draw()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(this->startX, this->startY) << (unsigned char)TL;
	conOut(this->startX, this->startY + 8 * TILE_WIDTH) << (unsigned char)TR;
	conOut(this->startX + TILE_HEIGHT, this->startY) << (unsigned char)BL;
	conOut(this->startX + TILE_HEIGHT, this->startY + 8 * TILE_WIDTH) << (unsigned char)BR;
	for (int i = 0; i < this->resources.size(); ++i)
	{
		this->resources[i]->draw();
	}
	for (int i = this->resources.size(); i < 8; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			conOut(this->startX + 2 + j, this->startY + 1 + i * TILE_WIDTH) << "          ";
		}
	}
}
void ResourceGrid::modifyMoney(int amount)
{
	if (amount <= money)
	{
		for (int i = 0; i < amount; ++i)
		{
			this->removeSun();
		}
	}
	money -= amount;
}