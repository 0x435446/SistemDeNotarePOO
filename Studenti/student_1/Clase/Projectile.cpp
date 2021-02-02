#include "Projectile.h"

using namespace GameMechanics;

Projectile::Projectile(int rowUp, int colLeft) : Entity(rowUp, colLeft)
{
}


Projectile::~Projectile()
{
}

void GameMechanics::Projectile::move()
{
	if (isColliding)
		return;
	this->colLeft++;
}

EffectInflicted GameMechanics::Projectile::getEffect()
{
	return inflictableEffect;
}
