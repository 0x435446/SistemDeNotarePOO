#include "Damageable.h"

using namespace GameMechanics;

Damageable::Damageable()
{
}


Damageable::~Damageable()
{
}

void GameMechanics::Damageable::receiveDamage(int damage)
{
	HP -= damage;
	if (HP < 0)
		HP = 0;
}

int GameMechanics::Damageable::getRemainingHP()
{
	return HP;
}
