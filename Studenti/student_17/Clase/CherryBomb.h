#pragma once
#include "Plant.h"
#include "Zombie.h"

#define CHERRYBOMB_EXPLODE_TIME		5
#define CHERRYBOMB_EXPLODE_DAMAGE	100
#define CHERRYBOMB_COST				250

class CherryBomb : public Plant
{
public:
	CherryBomb();
	~CherryBomb();
	int GetExplodeTime() const;
	int GetDamage() const;

	void HitZombie(Zombie& zombie);
private:
	int m_explodeTime;
	int m_damage;
};