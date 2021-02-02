#pragma once
#include "LifeForm.h"
#include "MoveableObject.h"
class Projectile :
	public Physical,
	public MoveableObject
{
	int damage;
public:
	Projectile(std::list<Physical*>& groupBoundTo,
		std::string sprite_file,
		C2D::Vector2 position,
		const std::list<Physical*>& everyZombieObject,
		int ProjectileSpeed,
		int damage);
	Projectile() = delete;
	Projectile(const Projectile&) = delete;
	Projectile& operator= (const Projectile&) = delete;
	virtual ~Projectile()
	{
	//	Projectile::End();
	}

	virtual void onCollide(Physical& physicalObject) override;

	virtual void Start() override;
	virtual void Update() override;
	virtual void End() override;

private:
	void do_damage(LifeForm& lifeForm);
};

