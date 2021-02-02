#pragma once
#include "Plants.h"


class PlantCherryBomb : public Plants
{
	int damage;
public:
	PlantCherryBomb();
	PlantCherryBomb(const int health, const std::string name, const int damage) : Plants(health, name), damage(damage) {};
	const int getDamage() { return this->damage; }
	~PlantCherryBomb();
};

