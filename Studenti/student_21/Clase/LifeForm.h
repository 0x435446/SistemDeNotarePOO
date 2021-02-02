#pragma once
#include "Physical.h"
#include "BiologicalComponent.h"
class LifeForm :
	public Physical
{
	BiologicalComponent<LifeForm> biologicalComponent;
public:
	LifeForm(std::list<Physical*>& groupBoundTo,
		std::string sprite_file,
		C2D::Vector2 position,
		const std::list<Physical*>& everyPhysicalObject,
		int healthPoints,
		int baseHpRegen,
		int updateReference);
	LifeForm(std::list<Physical*>& groupBoundTo,
		std::string sprite_file,
		C2D::Vector2 position,
		const std::list<Physical*>& everyPhysicalObject,
		int healthPoints,
		int updateReference);
	LifeForm() = delete;
	LifeForm(const LifeForm&) = delete;
	LifeForm& operator= (const LifeForm&) = delete;
	virtual ~LifeForm() {}

	virtual void onCollide(Physical&) = 0;
	virtual void onDeath()
	{
		_mark_for_death();
	}
	void takeDamage(int amount_of_damage)
	{
		biologicalComponent.takeDamage(amount_of_damage);
	}

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void End() = 0;
};

