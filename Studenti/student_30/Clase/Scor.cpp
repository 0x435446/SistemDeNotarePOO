#include "Scor.h"

Scor *Scor::instance = nullptr;

Scor * Scor::getInstance()
{
	if (instance == nullptr)
		instance = new Scor();
	return instance;
}

Scor::Scor()
{
}

Scor::Scor(int a, int b)
{
	x = a;
	y = b;
	vect.push_back(new Zona(x, y + 4));
}

Scor::~Scor()
{
}

void Scor::set_valoare()
{
	valoare =valoare+ 25;
}

void Scor::draw()
{
	for (auto it : vect)
	{
		it->draw_zona_scor_sun();
	}
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(3, 8) << valoare;
}

void Scor::update(std::string action)
{
	
}