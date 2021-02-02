#include "Sunflower.h"



Sunflower::Sunflower()
{
}

Sunflower::Sunflower(int a, int b)
{
	x = a;
	y = b;
}

Sunflower::~Sunflower()
{
}

void Sunflower::draw()
{
	UserInterface::ConsoleOutput out = UserInterface::ConsoleOutput::getInstance();
	out(x, y-1) << "^^^";
	out(x + 1, y - 1) << "<";
	out(x + 1, y) << "S";
	out(x + 1, y + 1) << ">";
}

void Sunflower::set(int valoare, int frecventa, int rezistenta)
{
	this->valoare = valoare;
	this->frecventa = frecventa;
	this->rezistenta = rezistenta;
}

void Sunflower::action()
{
	for (auto it : pea_vect)
		it->move();
}