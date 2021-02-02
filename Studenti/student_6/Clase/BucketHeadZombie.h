#pragma once
#include"Zombie.h"

class BucketHeadZombie:public Zombie
{
public:
	BucketHeadZombie(int,int);
	~BucketHeadZombie();

	int place_zombie3();
};

