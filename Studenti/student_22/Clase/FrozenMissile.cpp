#include "FrozenMissile.h"
#define base_specialEfect 0.7f;


FrozenMissile::FrozenMissile(int pozX, int pozY, bool isMoving, short int movement)
	: Missile(pozX, pozY, isMoving, movement)
{
	specialEfect = base_specialEfect;
}


FrozenMissile::~FrozenMissile()
{
}
