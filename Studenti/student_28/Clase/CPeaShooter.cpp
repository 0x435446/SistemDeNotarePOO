#include "CPeaShooter.h"



CPeaShooter::CPeaShooter(const int& speed, const int& type, const int& cost, const int& maxBites)
	:CPlant(speed, type, cost, maxBites)
{
}

void CPeaShooter::drawEntity(int row,int col)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(row, col) << static_cast <char>(m_type);
}

int CPeaShooter::getValue()
{
	return m_cost;
}

int CPeaShooter::getMaxBites()
{
	return m_maxBites;
}

void CPeaShooter::reduceHealth(int val)
{
	if (m_maxBites == 0) throw new CException(SUB_ERR, "Peashooter should've died!");
	else m_maxBites -= val;
}