#pragma once
#include "Zombie.h"
class RegularZombie :
	public Zombie
{
protected:
	//Constructor folosit pentru clase derivate
	RegularZombie(int HitPoints, int AttackDamage, int AttackSpeed, int MovementSpeed, wchar_t cSign, COORD Center) :Zombie(HitPoints, AttackDamage, AttackSpeed, MovementSpeed, cSign, Center) {}
public:
	RegularZombie(COORD Center):Zombie(10, 10, 1000, 50, REGULARZOMBIE, Center){}
	~RegularZombie(){}
	//Behavior
	virtual bool Draw(Panel&) override;
	virtual bool Erase(Panel&) override;
};

