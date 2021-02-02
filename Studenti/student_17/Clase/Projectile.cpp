#include "Projectile.h"

Projectile::Projectile(int x, int y) : m_type(NoProjectileType), m_damage(PROJECTILE_DAMAGE)
{
	this->SetMoving(true);
	this->SetPosition(x, y);
	this->SetSpeed(PROJECTILE_SPEED);
}

Projectile::~Projectile()
{
}

ProjectileType Projectile::GetType() const
{
	return this->m_type;
}

int Projectile::GetDamage() const
{
	return this->m_damage;
}

void Projectile::SetType(const ProjectileType type)
{
	this->m_type = type;
}

void Projectile::SetDamage(const int damage)
{
	this->m_damage = damage;
}