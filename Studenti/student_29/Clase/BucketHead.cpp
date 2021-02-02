#include "BucketHead.h"




BucketHead::BucketHead(const unsigned int& posX, const unsigned int& posY, char c) : Zombie(posX, posY, c)
{
	life = 18;
	move_speed = 1;
}

void BucketHead::attack()
{
}

BucketHead::~BucketHead()
{
}
