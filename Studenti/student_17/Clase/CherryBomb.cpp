#include "CherryBomb.h"

CherryBomb::CherryBomb() : m_explodeTime(CHERRYBOMB_EXPLODE_TIME), m_damage(CHERRYBOMB_EXPLODE_DAMAGE)
{
	this->SetType(CherryBombType);
	this->SetCost(CHERRYBOMB_COST);
}

CherryBomb::~CherryBomb()
{
}

int CherryBomb::GetExplodeTime() const
{
	return this->m_explodeTime;
}

int CherryBomb::GetDamage() const
{
	return this->m_damage;
}

void CherryBomb::HitZombie(Zombie& zombie)
{
	zombie.GetHit(this->GetDamage(), 0);
	delete this;
}