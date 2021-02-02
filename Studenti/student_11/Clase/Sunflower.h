#pragma once
#include "CoreObject.h"
class Sunflower :public CoreObject
{
public:
	Sunflower();
	~Sunflower();
	void setPosition(int x, int y);
	int getCost();
};

