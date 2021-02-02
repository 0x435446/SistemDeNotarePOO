#include "COrdinaryZombie.h"



COrdinaryZombie::COrdinaryZombie(const int& movingspeed, const int& health,const int& speed,const int& type)
	:CZombie(movingspeed,health,speed,type)
{
}

void COrdinaryZombie::reduceHealth(int val)
{
	if (val >= this->m_health)
	{
		this->m_health = 0;
	}
	else this->m_health -= val;
}

void COrdinaryZombie::drawEntity(int row,int col)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(row, col) << static_cast<char>(m_type);
}

int COrdinaryZombie::getAscii()
{
	return m_type;
}

int COrdinaryZombie::getSpeed()
{
	return m_speed;
}

int COrdinaryZombie::getValue()
{
	return m_health;
}

int COrdinaryZombie::getMaxBites()
{
	if (isPlant()) return 1;
	return 0;
}

int COrdinaryZombie::getMovingSpeed()
{
	return m_movingspeed;
}

COrdinaryZombie::~COrdinaryZombie()
{
}
