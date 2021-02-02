#pragma once
#include "Zombie.h"
class PoleVaultingZombie :
	public Zombie
{
public:
	PoleVaultingZombie(int pozX, int pozY, bool isMoving);
	~PoleVaultingZombie();
	void jump(Plant* e, int spriteSize);
};

