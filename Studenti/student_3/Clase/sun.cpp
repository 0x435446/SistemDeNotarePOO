#include "sun.h"



sun::sun(int x, int y)
{
	lifePoints = 0;
	bool dead = true;
	attackPoints = 25;
	pos_x = x;
	pos_y = y;
	Log::getInstance().displayMessage("Creating new sun. \n");
}

sun::~sun()
{
}
