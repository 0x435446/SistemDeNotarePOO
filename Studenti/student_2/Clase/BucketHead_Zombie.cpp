#include "BucketHead_Zombie.h"



BucketHead_Zombie::BucketHead_Zombie(int x, int y) : Zombie(x, y)
{
}

void BucketHead_Zombie::print(int x, int y)
{
	conOut(x, y) << "BucketHead";
	conOut(x + 1, y) << "Zombie ";
}

BucketHead_Zombie::~BucketHead_Zombie()
{
}
