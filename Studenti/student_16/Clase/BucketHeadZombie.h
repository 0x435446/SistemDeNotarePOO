#pragma once
#include "Zombie.h"
class BucketHeadZombie : public Zombie
{

public:
	BucketHeadZombie(int, int);
	~BucketHeadZombie() { ; }
	void draw();
	void executeFunction();
private:


};

