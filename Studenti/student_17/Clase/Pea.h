#pragma once
#include "Projectile.h"

class Pea : public Projectile
{
public:
	Pea(int x, int y);
	~Pea();

	virtual void HitZombie(Zombie& zombie) override;
};