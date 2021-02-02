#pragma once
#include "Plant.h"
#include "ShotPea.h"
#include "AbNothing.h"
class PeaShooter :
	public Plant
{
protected:
	//Constructor folosit pentru clase derivate
	PeaShooter(int HitPoints, int AttackDamage, int AttackSpeed, int Cost, wchar_t cSign,COORD Center):Plant(HitPoints, AttackDamage, AttackSpeed, Cost, cSign, Center){}
	void MoveShots(Panel& panel, Zombie& zombie);
public:
	//Constructor
	PeaShooter(COORD Center) :Plant(10, 10, 5000, 100, PEASHOOTER, Center){}
	~PeaShooter(){}
	//Override Shoot
	virtual void Shoot(Panel&, Zombie&) override;
	//Override Ability
	virtual void Ability(Panel&) override{}
	//Behavior
	virtual bool Draw(Panel& panel) override;
	virtual bool Erase(Panel& panel) override;
};

