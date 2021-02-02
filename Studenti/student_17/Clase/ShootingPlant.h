#pragma once
#include "Plant.h"

#define SHOOTING_SPEED_RATE 30

class Projectile;

class ShootingPlant : public Plant
{
public:
	ShootingPlant();
	virtual ~ShootingPlant();
	int GetSpeedRate() const;

	virtual Projectile* CreateProjectile() abstract;
protected:
	void SetSpeedRate(const int speed_rate);
private:
	int m_speedRate;
};