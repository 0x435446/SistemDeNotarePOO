#pragma once
#include "Plants.h"


class PlantFrozenPea : public Plants
{
public:
	PlantFrozenPea();
	PlantFrozenPea(const int health, const std::string name, const int shootTime) : Plants(health, name, shootTime) {};
	virtual ~PlantFrozenPea();
};

