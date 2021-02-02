#include "CProiectil.h"


CProiectil::CProiectil(const int& movingspeed,const int& damageDealt,const int& speed, const int& type)
	:CEntity(speed, type),m_damageDealt(damageDealt),m_movingspeed(movingspeed)
{
}

CProiectil::~CProiectil()
{
}
