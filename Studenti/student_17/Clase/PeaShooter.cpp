#include "PeaShooter.h"
#include "Pea.h"

PeaShooter::PeaShooter()
{
	this->SetType(PeaShooterType);
	this->SetCost(PEASHOOTER_COST);
}

PeaShooter::~PeaShooter()
{
}

Projectile* PeaShooter::CreateProjectile()
{
	return new Pea(this->GetX(), this->GetY());
}