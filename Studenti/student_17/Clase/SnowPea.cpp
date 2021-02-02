#include "SnowPea.h"

SnowPea::SnowPea(int x, int y) : Projectile(x, y), m_slowProcent(SNOW_PEA_SLOW_PROCENT)
{
	this->SetType(SnowPeaType);
}

SnowPea::~SnowPea()
{
}

int SnowPea::GetSlowProcent() const
{
	return this->m_slowProcent;
}

void SnowPea::HitZombie(Zombie& zombie)
{
	zombie.GetHit(PROJECTILE_DAMAGE, SNOW_PEA_SLOW_PROCENT);
	this->~SnowPea();
}