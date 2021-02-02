#pragma once
#include "Plants.h"


class PlantWallNut : public Plants
{

public:
	PlantWallNut();
	PlantWallNut(const int health, const std::string name) : Plants(health, name) {};
	virtual ~PlantWallNut();
};

