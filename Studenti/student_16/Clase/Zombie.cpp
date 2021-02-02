#include "Zombie.h"
Zombie::Zombie(int sX, int sY,std::string name)
{
	this->startX = sX;
	this->startY = sY;
	this->begin = steady_clock::now();
	this->eatClock = steady_clock::now();
	this->hitpoints = 3;
	if (name == "BucketHeadZombie")
	{
		this->hitpoints = 6;
	}
	this->points = 10;
	if (name == "BucketHeadZombie")
	{
		this->points = 25;
		if (name == "PoleVaultingZombie")
		{
			this->points = 15;
		}
	}
	this->name = name;
}
void Zombie::draw()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	std::ifstream fin("zombie.txt");
	int j = 1;
	char buff[1024];
	while (!fin.eof())
	{
		fin.getline(buff, 1024);
		conOut(this->startX + j, this->startY) << buff;
		j++;
	}
	fin.close();
	if (!this->eating)
	{
		auto end = steady_clock::now();
		if (duration_cast<milliseconds>(end - begin).count() > 250)
		{
			begin = end;
			conOut(this->startX + 1, this->startY + 1) << " ";
			conOut(this->startX + 2, this->startY + 2) << " ";
			conOut(this->startX + 3, this->startY + 2) << " ";
			conOut(this->startX + 4, this->startY + 3) << " ";
			this->startY -= 1;
		}
	}
}
Zombie::~Zombie()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	for (int j = 1; j <= 4; ++j)
	{
		conOut(this->startX + j, this->startY) << "    ";
	}
}
void Zombie::eat(Plant* plant)
{
	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - eatClock).count() > 350)
	{
		begin = end;
		plant->reduceResistance();
	}
}
void Zombie::executeFunction()
{
	;
}
