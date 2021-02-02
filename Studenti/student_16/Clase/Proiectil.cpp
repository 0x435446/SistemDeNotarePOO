#include "Proiectil.h"
Proiectil::Proiectil(int sX, int sY)
{
	this->begin = steady_clock::now();
	this->startX = sX;
	this->startY = sY;
}
void Proiectil::draw()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(this->startX, this->startY) << "#-->";
}
Proiectil::~Proiectil()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	for (int j = 3; j >= 0; j--)
	{
		conOut(this->startX, this->startY + j) << " ";
	}
}
void Proiectil::executeFuncion()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	auto end = steady_clock::now();
	if (this->startY < LIMIT)
	{
		if (duration_cast<milliseconds>(end - begin).count() > 20)
		{
			begin = end;
			conOut(this->startX, this->startY) << " ";
			this->startY += 1;
			this->draw();
		}
	}
}