#pragma once
#include "LifeForm.h"
#include "MoveableObject.h"
#include "InteractableObject.h"
class Zombie :
	public LifeForm,
	public MoveableObject
{
	int damage;
protected:
	std::list<InteractableObject*>& pCurrency;
public:
	Zombie(std::list<Physical*>& groupBoundTo,
		std::string sprite_file,
		C2D::Vector2 position,
		const std::list<Physical*>& everyLifeFormObject,
		std::list<InteractableObject*>& pCurrency,
		int damage,
		int speed,
		int direction,
		int healthPoints,
		int baseHpRegen);
	Zombie(std::list<Physical*>& groupBoundTo,
		std::string sprite_file,
		C2D::Vector2 position,
		const std::list<Physical*>& everyLifeFormObject,
		std::list<InteractableObject*>& pCurrency,
		int damage,
		int speed,
		int direction,
		int healthPoints);
	Zombie() = delete;
	Zombie(const Zombie&) = delete;
	Zombie& operator= (const Zombie&) = delete;
	virtual ~Zombie()
	{
		//	Zombie::End();
	}

	virtual void onCollide(Physical& physicalObject) override;

	virtual void Start() override;
	virtual void Update() override;
	virtual void End() override;

private:
	void do_damage(LifeForm& lifeForm);
};


