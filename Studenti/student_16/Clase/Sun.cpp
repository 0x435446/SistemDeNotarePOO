#include "Sun.h"
Sun::Sun(int x, int y)
{
	this->startX = x;
	this->startY = y;
}
void Sun::draw()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	std::ifstream fin("sun.txt");
	int i = 0;
	char buff[1024];
	while (!fin.eof())
	{
		fin.getline(buff, 1024);
		conOut(this->startX + i, this->startY) << buff;
		++i;
	}
	fin.close();
}