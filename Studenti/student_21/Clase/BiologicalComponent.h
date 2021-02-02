#pragma once
#include "Component.h"
template <class LifeFormObject>
class BiologicalComponent :
	public Component
{
	LifeFormObject& parent;
	int healthPoints;
	int baseHPRegen;
public:
	BiologicalComponent() = delete;
	BiologicalComponent(const BiologicalComponent&) = delete;
	BiologicalComponent& operator=(const BiologicalComponent&) = delete;
	BiologicalComponent(LifeFormObject& parent,
		int healthPoints,
		int baseHPRegen) :
		parent(parent),
		Component(Component::Type::BIOLOGICAL, 0, false),
		healthPoints(healthPoints),
		baseHPRegen(baseHPRegen) {}
	BiologicalComponent(LifeFormObject& parent,
		int healthPoints) :
		parent(parent),
		Component(Component::Type::BIOLOGICAL, 0, false),
		healthPoints(healthPoints),
		baseHPRegen(0) {}
	~BiologicalComponent() {}

	void takeDamage(int amount_of_damage) { healthPoints -= amount_of_damage; }

private:
	void Start() override final {}
	void Update() override final
	{
		if (healthPoints <= 0)
			die();
	}
	void End() override final {}

	void die()
	{
		parent.onDeath();
	}
	void healOverTime()
	{
		healthPoints += baseHPRegen;
	}
};

