#include "Resurse.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <chrono>
#include "Sun.h"
#include "Scor.h"
using namespace std::chrono;



Resurse::Resurse()
{

}

Resurse::Resurse(int x,int y)
{
	this->x = x;
	this->y = y;
	for (int i = 0; i < 10; i++)
	{
		vect.push_back(new Zona(x, y + i * 8));
	}
}


Resurse::~Resurse()
{
}

void Resurse::set_position(int a, int b)
{
	x = a;
	y = b;
}


void Resurse::update(std::string action)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	int poz_sun = rand() % 10;
	auto end = steady_clock::now();
	while (vect[poz_sun]->is_filled() == true)
	{
		poz_sun = rand() % 10;
	}
	if (duration_cast<milliseconds>(end - begin).count() >2150)
	{
		begin = end;
		Sun sun(vect[poz_sun]->get_x()+2, vect[poz_sun]->get_y()+3);
		vect[poz_sun]->set_filed();
		sun.draw();
	}
	for (auto it : vect)
	{
		if (it->is_filled() &&it->selected(action))
		{
			it->set_free();
			Scor *scor = Scor::getInstance();
			scor->set_valoare();
		}
	}
}


void Resurse::draw()
{
	for (auto it : vect)
		it->draw_zona_resurse();
}