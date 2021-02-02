#pragma once
#include"PeaShooter.h"
#include"ShotFrozenPea.h"
#include "AbSlow.h"
class SnowPeaShooter:
	public PeaShooter
{
public:
	SnowPeaShooter(COORD Center) :PeaShooter(10, 10, 5000, 150, SNOWPEASHOOTER, Center) {}
	~SnowPeaShooter(){}
	//Override Shoot
	virtual void Shoot(Panel&, Zombie&) override;
	//Override Ability
	virtual void Ability(Panel&) override;
	//Behavior mostenit
	//virtual bool Draw(Panel& panel) override;
	//virtual bool Erase(Panel& panel) override;
};

