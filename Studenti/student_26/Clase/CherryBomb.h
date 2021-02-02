#pragma once
#include "Plant.h"
#include"AbExplode.h"
class CherryBomb :
	public Plant
{
public:
	//Constructor
	CherryBomb(COORD Center):Plant(1,100,0,150,CHERRYBOMB,Center){}
	~CherryBomb(){}

	//Override Shoot
	virtual void Shoot(Panel&,Zombie&) override {}
	//Override Ability
	virtual void Ability(Panel&) override {}

	//Behavior
	virtual bool Draw(Panel& panel) override;
	virtual bool Erase(Panel& panel) override;
};

