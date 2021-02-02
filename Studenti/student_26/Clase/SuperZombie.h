#pragma once
#include "BucketHead.h"
#include "PoleVaultingZombie.h"
class SuperZombie :
	public BucketHead, public PoleVaultingZombie
{
protected:
	//Constructor folosit pentru clase derivate
	SuperZombie(int HitPoints, int AttackDamage, int AttackSpeed, int MovementSpeed, wchar_t cSign, COORD Center) :PoleVaultingZombie(HitPoints, AttackDamage, AttackSpeed, MovementSpeed, cSign, Center), BucketHead(HitPoints, AttackDamage, AttackSpeed, MovementSpeed, cSign, Center), RegularZombie(HitPoints, AttackDamage, AttackSpeed, MovementSpeed, cSign, Center) {}
public:
	SuperZombie(COORD Center) :PoleVaultingZombie(30, 10, 1000, 100, SUPERZOMBIE, Center), BucketHead(30, 10, 1000, 100, SUPERZOMBIE, Center), RegularZombie(30, 10, 1000, 100, SUPERZOMBIE, Center) {}
	~SuperZombie() {}
};

