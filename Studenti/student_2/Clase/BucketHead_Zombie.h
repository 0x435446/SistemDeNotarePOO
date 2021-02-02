#pragma once
#include "Zombie.h"
class BucketHead_Zombie :public Zombie
{
public:
	BucketHead_Zombie() :Zombie() {}
	BucketHead_Zombie(int x, int y);
	void print(int x, int y)override;
	~BucketHead_Zombie();
};

