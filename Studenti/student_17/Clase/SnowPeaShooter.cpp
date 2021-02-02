#include "SnowPeaShooter.h"
#include "SnowPea.h"

SnowPeaShooter::SnowPeaShooter()
{
	this->SetType(SnowPeaShooterType);
	this->SetCost(SNOWPEASHOOTER_COST);
}

SnowPeaShooter::~SnowPeaShooter()
{
}

Projectile* SnowPeaShooter::CreateProjectile()
{
	return new SnowPea(this->GetX(), this->GetY());
}