#include "CherryBomb.h"
#include "Battlefield.h"
CherryBomb::CherryBomb(int sX, int sY)
{
	this->startX = sX;
	this->startY = sY;
	this->name = "CherryBomb";

}
void CherryBomb::draw()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	std::ifstream fin("cherrybomb.txt");
	char buff[1024];
	int j = 1;
	while (!fin.eof())
	{
		fin.getline(buff, 1024);
		conOut(this->startX + j, this->startY + (TILE_WIDTH - string(buff).size()) / 2) << buff;
		++j;
	}
	fin.close();
}
void CherryBomb::executeFunction()
{
	this->draw();

}