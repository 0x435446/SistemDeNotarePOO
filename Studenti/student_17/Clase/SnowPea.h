#pragma once
#include "Projectile.h"

#define SNOW_PEA_SLOW_PROCENT 10

class SnowPea : public Projectile
{
public:
	SnowPea(int x, int y);
	~SnowPea();
	int GetSlowProcent() const;

	virtual void HitZombie(Zombie& zombie) override;
private:
	int m_slowProcent;
};