#include "PoleVaultingZombie.h"
#define base_health 2
#define special_sauce 2

PoleVaultingZombie::PoleVaultingZombie(int pozX, int pozY, bool isMoving)
	:Zombie(pozX, pozY, isMoving)
{
	health = base_health;
	canJump = true;
}


PoleVaultingZombie::~PoleVaultingZombie()
{
}

void PoleVaultingZombie::jump(Plant * e, int spriteSize)
{
	canJump = false;
	lastPozX = pozX;
	pozX = e->getPozX() - spriteSize - special_sauce;
	this->sprite.loadSprite("zombie.spr");
}
