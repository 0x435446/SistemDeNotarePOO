#pragma once
#include "Plant.h"
class WallNut :
	public Plant
{
public:
	WallNut(int pozX, int pozY);
	~WallNut();
	float getHealth();
	std::string getAttackingType();
private:
	
};

