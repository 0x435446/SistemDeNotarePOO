#pragma once
#include "DisplayableEntity.h"
#include "Zombie.h"

#define PROJECTILE_DAMAGE	50
#define PROJECTILE_SPEED	60

enum ProjectileType
{
	NoProjectileType = 0, PeaType, SnowPeaType
};

class Projectile : public DisplayableEntity
{
public:
	Projectile(int x, int y);
	virtual ~Projectile();
	ProjectileType GetType() const;
	int GetDamage() const;

	virtual void HitZombie(Zombie& zombie) abstract;
protected:
	void SetType(const ProjectileType type);
	void SetDamage(const int damage);
private:
	ProjectileType m_type;
	int m_damage;
};