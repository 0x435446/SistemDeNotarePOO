#include "CSunflower.h"



CSunflower::CSunflower(const int& speed, const int& type, const int& cost, const int& maxBites)
	:CPlant(speed, type, cost, maxBites)
{
}

void CSunflower::drawEntity(int row,int col)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(row, col) << static_cast <char>(m_type);
}

int CSunflower::getValue()
{
	return m_cost;
}

int CSunflower::getMaxBites()
{
	return m_maxBites;
}

int CSunflower::getAscii()
{
	return m_type;
}

int CSunflower::getSpeed()
{
	return m_speed;
}

void CSunflower::reduceHealth(int val)
{
	if (m_maxBites == 0) throw new CException(SUB_ERR, "Sunflower should've died!");
	else m_maxBites -= val;
}

CSunflower::~CSunflower()
{
}
