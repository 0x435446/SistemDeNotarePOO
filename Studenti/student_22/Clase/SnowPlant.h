#pragma once
#include "Plant.h"
class SnowPlant : public Plant
{
public:
	SnowPlant(int pozX, int pozY);
	std::string getAttackingType();
	~SnowPlant();
};

