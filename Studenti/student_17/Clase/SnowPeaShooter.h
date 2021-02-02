#pragma once
#include "ShootingPlant.h"

#define SNOWPEASHOOTER_COST 300

class SnowPeaShooter : public ShootingPlant
{
public:
	SnowPeaShooter();
	~SnowPeaShooter();

	Projectile* CreateProjectile() override;
};