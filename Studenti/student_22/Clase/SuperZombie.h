#pragma once
#include "Zombie.h"
class SuperZombie :
	public Zombie
{
public:
	SuperZombie(int pozX, int pozY, bool isMoving);
	~SuperZombie();
	virtual void jump(Plant* e, int spriteSize);
};

