#pragma once
#include "Plant.h"
class WallNut :
	public Plant
{
public:
	//Constructor
	WallNut(COORD Center):Plant(100,0,0,50,WALLNUT,Center){}
	~WallNut() {}
	//Override Shoot
	virtual void Shoot(Panel&,Zombie&) override {}
	//Override Ability
	virtual void Ability(Panel&) override {}
	//Behavior
	virtual bool Draw(Panel& panel) override;
	virtual bool Erase(Panel& panel) override;

};

