#pragma once
#include "RegularZombie.h"
#include "AbJumpOver.h"
class PoleVaultingZombie :
	virtual public RegularZombie
{
protected:
	//Constructor folosit pentru clase derivate
	PoleVaultingZombie(int HitPoints, int AttackDamage, int AttackSpeed, int MovementSpeed, wchar_t cSign, COORD Center) :RegularZombie(HitPoints, AttackDamage, AttackSpeed, MovementSpeed, cSign, Center) {}
public:
	PoleVaultingZombie(COORD Center) :RegularZombie(10, 10, 1000, 100, POLEVAULTING, Center) {}
	~PoleVaultingZombie() {}
	//Pentru Ability trebuie rescrisa metoda de fight

};

