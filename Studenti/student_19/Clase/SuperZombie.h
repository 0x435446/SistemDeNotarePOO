#pragma once
#include "PoleVaultingZombie.h"
#include "BucketHeadZombie.h"

class SuperZombie :
	virtual public Zombie
{
public:
	SuperZombie();
	SuperZombie(const int health, const int speed, const int damage, const std::string name, const int x, const int y, const int ability) :
		Zombie(health, speed, damage, name, x, y, ability) {};
	virtual ~SuperZombie();
};

