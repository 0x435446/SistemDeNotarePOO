#pragma once
#include "Plants.h"

class PlantSunflower : public Plants
{
public:
	PlantSunflower();
	PlantSunflower(const int health, const std::string name) : Plants(health, name) {};
	virtual ~PlantSunflower();
};

