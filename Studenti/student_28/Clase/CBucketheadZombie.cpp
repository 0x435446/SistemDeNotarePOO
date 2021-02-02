#include "CBucketheadZombie.h"



CBucketheadZombie::CBucketheadZombie(const int& movingspeed, const int& health, const int& speed, const int& type)
	:CZombie(movingspeed, health, speed, type)
{
}


void CBucketheadZombie::reduceHealth(int val)
{
	if (val >= this->m_health)
	{
		this->m_health = 0;
	}
	else this->m_health -= val;
}

void CBucketheadZombie::drawEntity(int row, int col)
{
	UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(row, col) << static_cast<char>(m_type);
}

int CBucketheadZombie::getAscii()
{
	return m_type;
}

int CBucketheadZombie::getSpeed()
{
	return m_speed;
}

int CBucketheadZombie::getValue()
{
	return m_health;
}

int CBucketheadZombie::getMaxBites()
{
	if (isPlant()) return 1;
	return 0;
}

int CBucketheadZombie::getMovingSpeed()
{
	return m_movingspeed;
}

CBucketheadZombie::~CBucketheadZombie()
{
}
