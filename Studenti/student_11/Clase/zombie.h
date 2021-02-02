#pragma once
#include "CoreObject.h"
class zombie :public CoreObject
{
public:
	zombie();
	zombie(int x, int y);
	~zombie();
	void setPosition(int x, int y);
	int getX();
	int getY();
	void updateX(int x);
	void updateY(int y);
private:
	 int x, y=69;
};

