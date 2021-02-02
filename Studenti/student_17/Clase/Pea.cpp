#include "Pea.h"

Pea::Pea(int x, int y) : Projectile(x, y)
{
	this->SetType(PeaType);
}

Pea::~Pea()
{
}

void Pea::HitZombie(Zombie& zombie)
{
	zombie.GetHit(PROJECTILE_DAMAGE, 0);
	this->~Pea();
}