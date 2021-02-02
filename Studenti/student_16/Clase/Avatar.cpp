#include "Avatar.h"
Avatar::Avatar(std::string plant, int sX, int sY)
{
	this->plantName = plant;
	this->startX = sX;
	this->startY = sY;
	if (plant == "Sunflower")
	{
		this->cost = 2;
	}
	if (plant == "PeaShooter")
	{
		this->cost = 3;
	}
	if (plant == "WallNut")
	{
		this->cost = 4;
	}
	if (plant == "CherryBomb")
	{
		this->cost = 4;
	}
}
void Avatar::draw()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(this->startX , this->startY + (TILE_WIDTH - plantName.size()) / 2) << this->plantName;
	if (this->plantName == "Sunflower")
	{
		ifstream fin("sunflower.txt");
		int j = 1;
		char buff[1024];
		while (!fin.eof())
		{
			fin.getline(buff, 1024);
			conOut(this->startX + j, this->startY + (TILE_WIDTH - string(buff).size()) / 2) << buff;
			++j;
		}
		fin.close();
		conOut(this->startX + j, this->startY + (TILE_WIDTH - 8) / 2) <<"Cost: "<< this->cost<<(unsigned char)234;
	}
	if (this->plantName == "PeaShooter")
	{
		ifstream fin("peashooter.txt");
		int j = 1;
		char buff[1024];
		while (!fin.eof())
		{
			fin.getline(buff, 1024);
			conOut(this->startX + j, this->startY + (TILE_WIDTH - string(buff).size()) / 2) << buff;
			++j;
		}
		fin.close();
		conOut(this->startX + j, this->startY + (TILE_WIDTH - 8) / 2) << "Cost: " << this->cost<<(unsigned char)234;
		fin.close();
	}
	if (this->plantName == "WallNut")
	{
		ifstream fin("wallnut.txt");
		int j = 1;
		char buff[1024];
		while (!fin.eof())
		{
			fin.getline(buff, 1024);
			conOut(this->startX + j, this->startY + (TILE_WIDTH - string(buff).size()) / 2) << buff;
			++j;
		}
		fin.close();
		conOut(this->startX + j, this->startY + (TILE_WIDTH - 8) / 2) << "Cost: " << this->cost << (unsigned char)234;
		fin.close();
	}
	if (this->plantName == "CherryBomb")
	{
		ifstream fin("cherrybomb.txt");
		int j = 1;
		char buff[1024];
		while (!fin.eof())
		{
			fin.getline(buff, 1024);
			conOut(this->startX + j, this->startY + (TILE_WIDTH - string(buff).size()) / 2) << buff;
			++j;
		}
		fin.close();
		conOut(this->startX + j, this->startY + (TILE_WIDTH - 8) / 2) << "Cost: " << this->cost << (unsigned char)234;
		fin.close();
	}
}