#pragma once
#include "entity.h"
class plants : virtual public entity
{
public:
	plants();
	virtual void drawSunflower(int, int);
	virtual ~plants();
	virtual int getY() { return this->pos_y; }
	virtual int getX() { return this->pos_x; }
};

