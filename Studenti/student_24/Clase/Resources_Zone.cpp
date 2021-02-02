#include "Resources_Zone.h"
#include "ConsoleOutput.h"
#include "ConsoleInput.h"


void Resources_Zone::freee()
{
	sun = NULL;
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = x + 1; i < x + 5; i++)
		for (int j = y + 1; j < y + 8; j++)
			conOut(i, j) << " ";
}

void Resources_Zone::setfilled()
{
	filled = 1;
}

void Resources_Zone::setfree()
{
	filled = 0;
}

bool Resources_Zone::isfilled()
{
	return filled;
}


Resources_Zone::Resources_Zone()
{
	filled = 0;
	sun = NULL;
}


Resources_Zone::~Resources_Zone()
{
}

Resources_Zone::Resources_Zone(int a, int b)
{
	x = a;
	y = b;
	filled = 0;
}

void Resources_Zone::draw()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 1; i < 8; i++)
		conOut(x + 5, y + i) << "~";
	conOut(x + 4, y + 8) << "*";
	conOut(x + 4, y) << "*";
	if (this->isfilled())
		this->sun->draw();
}

void Resources_Zone::set_sun(Sun * sun)
{
	this->sun = sun;
}

void Resources_Zone::uppdate(std::string)
{

}
bool Resources_Zone::selected(std::string action)
{
	
	if (action.find("double") != std::string::npos)
	{
		std::string x, y;
		for (int i = action.find("(") + 1; i < action.find(","); i++)
			x += action[i];
		for (int i = action.find(",") + 1; i < action.find(")"); i++)
			y += action[i];
		int m_x, m_y;
		m_y = stoi(x);
		m_x = stoi(y);
		if (m_x >= this->x && m_x <= this->x + 6 && m_y >= this->y && m_y <= this->y + 7)
			return true;
	}
	return false;
}

