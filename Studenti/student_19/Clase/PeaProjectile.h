#pragma once
#include "Projectiles.h"

class PeaProjectile : public Projectiles
{
public:
	PeaProjectile();
	PeaProjectile(const int x, const int y, const int damage, const int frequency) : Projectiles(x, y, damage, frequency, 0) {};
	~PeaProjectile();
};

