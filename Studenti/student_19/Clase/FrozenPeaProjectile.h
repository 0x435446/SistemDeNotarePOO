#pragma once
#include "Projectiles.h"

class FrozenPeaProjectile : public Projectiles
{
public:
	FrozenPeaProjectile();
	FrozenPeaProjectile(const int x, const int y, const int damage, const int frequency, const int ability) : Projectiles(x, y, damage, frequency, ability) {};
	~FrozenPeaProjectile();
};

