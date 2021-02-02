#pragma once
#include "ShootingPlant.h"

#define PEASHOOTER_COST 200

class PeaShooter : public ShootingPlant
{
public:
	PeaShooter();
	~PeaShooter();

	Projectile* CreateProjectile() override;
};