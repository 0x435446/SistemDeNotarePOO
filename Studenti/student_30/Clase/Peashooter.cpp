#include "Peashooter.h"
#include <time.h>
#include <chrono>
using namespace std::chrono;

Peashooter::Peashooter()
{
}

Peashooter::Peashooter(int a, int b)
{
	x = a;
	y = b;
}

Peashooter::~Peashooter()
{
}


void Peashooter::draw()
{
	UserInterface::ConsoleOutput out = UserInterface::ConsoleOutput::getInstance();
	out(x, y-1) << "^^^";
	out(x + 1, y - 1) << "<";
	out(x + 1, y) << "P";
	out(x + 1, y + 1) << ">";
}

void Peashooter::set(int valoare, int frecventa, int rezistenta)
{
	this->valoare = valoare;
	this->frecventa = frecventa;
	this->rezistenta = rezistenta;
}


void Peashooter::action()
{
	for (auto it : pea_vect)
		it->move();
}