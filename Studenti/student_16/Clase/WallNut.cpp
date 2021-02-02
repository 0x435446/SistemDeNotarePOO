#include "WallNut.h"
WallNut::WallNut(int sX, int sY)
{
	this->startX = sX;
	this->startY = sY;
	this->biteResistance = 1000;
	this->bullet = nullptr;
}
void WallNut::draw()
{
	std::ifstream fin("wallnut.txt");
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	int j = 1;
	char buff[1024];
	while (!fin.eof())
	{
		fin.getline(buff, 1024);
		conOut(this->startX + j, this->startY + (TILE_WIDTH - string(buff).size()) / 2) << buff;
		++j;
	}
	fin.close();
}