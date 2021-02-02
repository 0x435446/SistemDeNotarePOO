#pragma once
#include "Plants.h"

class PlantPeaShooter : public Plants
{
public:
	PlantPeaShooter();
	PlantPeaShooter(const int health, const std::string name, const int shootTime) : Plants(health, name, shootTime) {};
	virtual ~PlantPeaShooter();
};

