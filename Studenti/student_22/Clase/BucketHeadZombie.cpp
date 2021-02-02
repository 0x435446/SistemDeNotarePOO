#include "BucketHeadZombie.h"
#define base_health 4


BucketHeadZombie::BucketHeadZombie(int pozX, int pozY, bool isMoving):
	Zombie(pozX, pozY, isMoving)
{
	this->health = base_health;
}


BucketHeadZombie::~BucketHeadZombie()
{
}

//void BucketHeadZombie::interact(Missile ** e)
//{
//	this->movingSpeed *= (*e)->getSpecial();
//	if (this->health - 1 == 0) {
//		this->isMoving = false;
//		this->isDead = true;
//	}
//	else
//		this->health--;
//	(*e)->setIsMoving(false);
//	(*e)->setIsDead(true);
//}
//
//void BucketHeadZombie::interact(Plant ** e)
//{
//	float plantHealth = (*e)->getHealth() - 1;
//	if (plantHealth == 0) {
//		this->isMoving = true;
//		(*e)->setIsDead(true);
//	}
//	(*e)->setHealth(plantHealth);
//}
