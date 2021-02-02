#include "CZombie.h"



CZombie::CZombie(const int& movingspeed, const int& health,const int& speed, const int& type)
	:CEntity(speed, type),m_health(health),m_movingspeed(movingspeed)
{
}

CZombie::~CZombie()
{
}
