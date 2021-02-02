#include "Projectiles.h"



Projectiles::Projectiles()
{
}

Projectiles::Projectiles(const int x, const int y, const int damage, const int frequency, const int ability)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 11);
	this->damage = damage;
	this->x = x;
	this->y = y;
	this->frequency = frequency;
	this->ability = ability;
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(this->y, this->x) << "*";
}

void Projectiles::move()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 11);
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(this->y, this->x) << " ";
	x += 1;
	if ((x + 3) % 5 == 0)
		x += 1;
	if (x % 5 == 0)
		x += 1;
	conOut(this->y, this->x) << "*";
}




Projectiles::~Projectiles()
{
}
