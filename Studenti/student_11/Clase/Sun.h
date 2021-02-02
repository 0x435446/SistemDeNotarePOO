#pragma once
#include "CoreObject.h"
class Sun :public CoreObject
{
public:
	Sun();
	~Sun();
	void setPosition(int x, int y);
	int getValue();
};

