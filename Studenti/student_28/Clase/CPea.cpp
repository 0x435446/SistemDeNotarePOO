#include "CPea.h"



CPea::CPea(const int& movingspeed,const int& damageDealt,const int& speed,const int& type)
	:CProiectil(movingspeed,damageDealt,speed,type)
{
}

int CPea::getValue()
{
	return m_damageDealt;
}

int CPea::getMaxBites()
{
	if (isResurse()) return 1;
	return 0;
}

void CPea::drawEntity(int row,int col)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(row, col) << static_cast<char>(m_type);
}

void CPea::reduceHealth(int val)
{
	m_damageDealt += val;
}

CPea::~CPea()
{
}
