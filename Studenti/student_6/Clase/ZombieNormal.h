#pragma once
#include"Zombie.h"
class ZombieNormal:public Zombie
{
public:
	ZombieNormal(int,int);
	~ZombieNormal();

	int place_zombie1();
	int place_zombie2();
};

