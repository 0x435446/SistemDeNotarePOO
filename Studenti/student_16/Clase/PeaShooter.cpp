#include "PeaShooter.h"
PeaShooter::PeaShooter(int sX, int sY)
{
	this->startX = sX;
	this->startY = sY;
	this->begin = steady_clock::now();
	this->biteResistance = 300;
	this->name = "PeaShooter";
}
void PeaShooter::executeFunction()
{
	this->draw();
	if (bullet)
	{
		bullet->executeFuncion();
	}
	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > 3000)
	{
		begin = end;
		if (!this->bullet)
		{
			bullet = new Proiectil(this->startX + 2, this->startY + 12);
		}
	}
	if (bullet&&bullet->getY() >= LIMIT)
	{
		delete bullet;
		bullet = nullptr;
	}
}
void PeaShooter::draw()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	std::ifstream fin("peashooter.txt");
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