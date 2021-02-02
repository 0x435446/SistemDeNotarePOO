#pragma once
#include "Missile.h"
class FrozenMissile :
	public Missile
{
public:
	FrozenMissile(int pozX, int pozY, bool isMoving, short int movement);
	~FrozenMissile();
};

