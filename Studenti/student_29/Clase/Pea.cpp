#include "Pea.h"


Pea::Pea(const int& a, const int& b) : Projectile(a, b, 248)
{
	move_speed = 2;
	dmg = 5;
}

Pea::~Pea()
{
}
