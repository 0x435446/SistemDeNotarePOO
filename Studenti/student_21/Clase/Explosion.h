#pragma once
#include "LifeForm.h"
class Explosion :
	public Physical
{
	int damage;
	bool exploded = false;
public:
	Explosion(std::list<Physical*>& groupBoundTo,
		std::string sprite_file,
		C2D::Vector2 position,
		const std::list<Physical*>& everyZombieObject,
		int updateReference,
		int damage) :
		Physical(groupBoundTo, sprite_file, position, everyZombieObject, updateReference),
		damage(damage)
	{
		Start();
	}
	Explosion() = delete;
	Explosion(const Explosion&) = delete;
	Explosion& operator= (const Explosion&) = delete;
	virtual ~Explosion() = default;

	virtual void Start() {
		GameObject::Start();
	}
	virtual void Update() {
		if (exploded)
		{
			_mark_for_death();
			RemoveComponent<Component::Type::COLLIDER>();
		}
		GameObject::Update();
		exploded = true;
	}
	virtual void End() {
		GameObject::End();
	}

	void onCollide(Physical& object) override final
	{
		if (!exploded)
			if (object.getType() == Physical::Type::LIFEFORM)
			{
				dynamic_cast<LifeForm&>(object).takeDamage(damage);
			}
		
	}
};

