#pragma once
#include "RegularZombie.h"
class BucketHead :
	virtual public RegularZombie
{
protected:
	//Constructor folosit pentru clase derivate
	BucketHead(int HitPoints, int AttackDamage, int AttackSpeed, int MovementSpeed, wchar_t cSign, COORD Center) :RegularZombie(HitPoints, AttackDamage, AttackSpeed, MovementSpeed, cSign, Center) {}
public:
	BucketHead(COORD Center) :RegularZombie(30, 10, 1000, 50, BUCKETHEAD, Center) {}
	~BucketHead() {}
};

