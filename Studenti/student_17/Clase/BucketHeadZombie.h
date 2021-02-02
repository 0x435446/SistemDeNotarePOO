#pragma once
#include "Zombie.h"

#define BUCKET_HEAD_ZOMBIE_HP 300

class BucketHeadZombie : virtual public Zombie
{
public:
	BucketHeadZombie(const int x, const int y);
	virtual ~BucketHeadZombie();
};