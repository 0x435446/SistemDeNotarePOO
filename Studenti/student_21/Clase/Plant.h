#pragma once
#include "LifeForm.h"
#include "Weapon.h"
#include "Projectile.h"
class Plant :
	public LifeForm
{
public:
	Plant(std::list<Physical*>& groupBoundTo,
		std::string sprite_file,
		C2D::Vector2 position,
		std::list<Physical*>& everyLifeFormObject,
		int healthPoints,
		int baseHpRegen);
	Plant(std::list<Physical*>& groupBoundTo,
		std::string sprite_file,
		C2D::Vector2 position,
		std::list<Physical*>& everyLifeFormObject,
		int healthPoints);
	Plant() = delete;
	Plant(const Plant&) = delete;
	Plant& operator= (const Plant&) = delete;
	virtual ~Plant()
	{
	//	Plant::End();
	}

	virtual void onCollide(Physical& physicalObject) override;

	virtual void Start() override;
	virtual void Update() override;
	virtual void End() override;


};

