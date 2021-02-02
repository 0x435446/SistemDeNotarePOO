#pragma once
#include "Plant.h"
#include "AbMakeSun.h"
class SunFlower :
	public Plant
{
public:
	//Constructor
	SunFlower(COORD Center) :Plant(20, 0, 0, 50, SUNFLOWER, Center) {}
	~SunFlower() {}
	//Override Shoot
	virtual void Shoot(Panel&,Zombie&) override {}
	//Override Ability
	virtual void Ability(Panel&) override {}
	//Behavior
	virtual bool Draw(Panel& panel) override;
	virtual bool Erase(Panel& panel) override;

};

