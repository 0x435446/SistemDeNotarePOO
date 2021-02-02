#pragma once
#include "Zombie.h"
class BucketHeadZombie : public Zombie
{
public:
	BucketHeadZombie(int pozX, int pozY, bool isMoving);
	~BucketHeadZombie();
	/*void interact(Missile** e);
	void interact(Plant** e);*/
private:
	
};

