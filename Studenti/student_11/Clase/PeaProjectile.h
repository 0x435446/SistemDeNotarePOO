#pragma once
#include "CoreObject.h"
class PeaProjectile :	public CoreObject
{
public:
	PeaProjectile();
	~PeaProjectile();
	void setPosition(int x, int y);
	int getX();
	int getY();
private:
	int x, y;
};
