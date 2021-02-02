#include "CResurse.h"



CResurse::CResurse(int value, int speed, int type)
	:m_value(value), CEntity(speed, type)
{
}

void CResurse::drawSun(int value)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(3, value) << static_cast<char>(m_type);
}

void CResurse::drawEntity(int row,int col)
{
	UserInterface::ConsoleInput &conIn = UserInterface::ConsoleInput::getInstance();
	std::string action = conIn.getUserActions();
	if (m_type == 167)
	{
		drawSun(col);
	}
}

void CResurse::changeSpeed(int number)
{
	this->m_speed = this->m_speed - number * 500;
}

int CResurse::getValue()
{
	return m_value;
}

int CResurse::getMaxBites()
{
	if (isPlant()) return 1;
	return 0;
}

void CResurse::reduceHealth(int val)
{
	m_speed -= 700;
}
