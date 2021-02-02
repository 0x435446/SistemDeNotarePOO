#include "Projectile.h"



void Projectile::move()
{
	y += move_speed;
}

Projectile::Projectile(const int& a, const int& b, const char& c) : x(a), y(b), ch(c)
{
}

Projectile::~Projectile()
{
}
