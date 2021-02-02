#include "Zona.h"
#include "Zombie_banal.h"


Zona::~Zona()
{
}

void Zona::draw()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 0; i < 7; i++)
	{
		conOut(x, y + i) << ".";
		conOut(x + 6, y + i) << ".";
		conOut(x + i, y) << ".";
		conOut(x + i, y + 6) << ".";
	}
	if (filled)
		caracter->draw();
}


void Zona::set_position(int a, int b)
{
	x = a;
	y = b;
}

bool Zona::selected(std::string action)
{

	if (action.find("double clicked") != std::string::npos)
	{
		std::string x, y;
		for (int i = action.find("(") + 1; i < action.find(","); i++)
			x += action[i];
		for (int i = action.find(",") + 1; i < action.find(")"); i++)
			y += action[i];
		int m_x, m_y;
		m_y = stoi(x);
		m_x= stoi(y);
		if (m_x >= this->x && m_x <= this->x + 6 && m_y >= this->y && m_y <= this->y + 7)
			return true;
	}
	return false;
}

bool Zona::is_filled()
{
	return filled;
}

void Zona::set_free()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	filled = 0;
	delete caracter;
	for (int i = x + 1; i < x + 5; i++)
		for (int j = y + 1; j < y + 8; j++)
			conOut(i, j) << " ";
}

void Zona::set_filed()
{
	filled = true;
}

void Zona::draw_zona_resurse()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 0; i < 7; i++)
	{
		conOut(x, y + i) << ":";
		conOut(x + 6, y + i) << ":";
		conOut(x + i, y) << ":";
		conOut(x + i, y + 6) << ":";
	}
}

void Zona::draw_zona_plante()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 0; i < 5; i++)
	{
		conOut(x+i, y ) << ":";
		conOut(x + i, y + 5) << ":";
		conOut(x , y+i) << ":";
		conOut(x + 5, y +i) << ":";
	}
}

void Zona::draw_zona_scor_sun()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 0; i < 6; i++)
	{
		conOut(x + i, y) << "=";
		conOut(x + i, y + 6) << "=";
		conOut(x, y + i) << "=";
		conOut(x + 6, y + i) << "=";
	}
}