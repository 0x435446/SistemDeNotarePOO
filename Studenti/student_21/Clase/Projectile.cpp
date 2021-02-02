#include "Projectile.h"


Projectile::Projectile(std::list<Physical*>& groupBoundTo,
	std::string sprite_file,
	C2D::Vector2 position,
	const std::list<Physical*>& everyZombieObject,
	int ProjectileSpeed,
	int damage) :
	Physical(groupBoundTo, sprite_file, position, everyZombieObject, ProjectileSpeed),
	MoveableObject(_transform(), ProjectileSpeed, 1 /* RIGHT */),
	damage(damage)
{
	Projectile::Start();
}

void Projectile::onCollide(Physical& physicalObject)
{
	if (physicalObject.getType() == Physical::Type::LIFEFORM) // should be zombie
	{
		_mark_for_death();
		do_damage(dynamic_cast<LifeForm&>(physicalObject));
	}
}

void Projectile::Start()
{
	BeginMoving();
	GameObject::Start();
}
void Projectile::Update() 
{
	BeginMoving();
	GameObject::Update();
	if (_transform().getPosition().getX() >= 153)
		_mark_for_death();
}
void Projectile::End() {}

void Projectile::do_damage(LifeForm& lifeForm)  //// no need for another base class for this one
{
	lifeForm.takeDamage(damage);
}
