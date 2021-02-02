#include "Zombie_banal.h"



Zombie_banal::Zombie_banal()
{
}

Zombie_banal::Zombie_banal(int a, int b)
{
	x = a;
	y = b;
}


Zombie_banal::~Zombie_banal()
{
}

void Zombie_banal::move()
{
		UserInterface::ConsoleOutput out = UserInterface::ConsoleOutput::getInstance();
		out(x, y + 1) << " ";
		Zombie_banal::draw();
		y--;
}

void Zombie_banal::set(int viteza, int rezistenta)
{
	this->viteza = viteza;
	this->rezistenta = rezistenta;
}


void Zombie_banal::draw()
{
	UserInterface::ConsoleOutput out = UserInterface::ConsoleOutput::getInstance();
	out(x, y - 1) << "**";
	out(x + 1, y - 1) << "(";
	out(x + 1, y) << "Z";
	out(x + 1, y + 1) << ")";
}