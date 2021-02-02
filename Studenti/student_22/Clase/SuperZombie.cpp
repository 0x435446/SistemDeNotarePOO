#include "SuperZombie.h"
#define special_sauce 2
#define base_health 4

SuperZombie::SuperZombie(int pozX, int pozY, bool isMoving) :
	Zombie(pozX, pozY, isMoving)
{
	health = base_health;
	canJump = true;
}


SuperZombie::~SuperZombie()
{
}

void SuperZombie::jump(Plant * e, int spriteSize)
{
	canJump = false;
	lastPozX = pozX;
	pozX = e->getPozX() - spriteSize - special_sauce;
	this->sprite.loadSprite("buckethead_zombie.spr");
}
