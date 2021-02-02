#pragma once
#include "Zombie.h"

class BucketHeadZombie : virtual public Zombie
{
public:
	BucketHeadZombie();
	BucketHeadZombie(const int health, const int speed, const int damage, const std::string name, const int x, const int y) :
		Zombie(health, speed, damage, name, x, y) {};
	virtual ~BucketHeadZombie();
};

