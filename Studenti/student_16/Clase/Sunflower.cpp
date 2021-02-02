#include "Sunflower.h"
Sunflower::Sunflower(int sX, int sY)
{
	this->startX = sX;
	this->startY = sY;
	this->begin = steady_clock::now();
	this->biteResistance = 200;
	this->name = "Sunflower";
	this->numberOfSuns = 0;
}
void Sunflower::draw()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	std::ifstream fin("sunflower.txt");
	char buff[1024];
	int j = 1;
	while (!fin.eof())
	{
		fin.getline(buff, 1024);
		conOut(this->startX + j, this->startY+(TILE_WIDTH-string(buff).size())/2) << buff;
		++j;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (i < numberOfSuns)
		{
			conOut(this->startX + j, this->startY + i + TILE_WIDTH / 2) << (unsigned char)234;
		}
		else
		{
			conOut(this->startX + j, this->startY + i + TILE_WIDTH / 2) <<" ";
		}
	}
	fin.close();
}
void Sunflower::executeFunction()
{
	auto end = steady_clock::now();
	if (numberOfSuns <4)
	{
		if (duration_cast<milliseconds>(end - begin).count() > 15000)
		{
			begin = end;
			numberOfSuns++;
		}
	}
	this->draw();
}