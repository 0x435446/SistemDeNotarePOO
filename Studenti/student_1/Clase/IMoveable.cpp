#include "IMoveable.h"

using namespace GameMechanics;

IMoveable::IMoveable()
{
	isColliding = false;
}


IMoveable::~IMoveable()
{
}

unsigned GameMechanics::IMoveable::getSpeed()
{
	return speed;
}

void IMoveable::setColliding(bool b)
{
	isColliding = b;
}

bool GameMechanics::IMoveable::getColliding()
{
	return isColliding;
}
