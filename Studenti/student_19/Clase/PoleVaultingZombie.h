#pragma once
#include "Zombie.h"
class PoleVaultingZombie : virtual public Zombie
{
	int ability_charges;
public:
	PoleVaultingZombie();
	PoleVaultingZombie(const int health, const int speed, const int damage, const std::string name, const int x, const int y, const int ability) :
		Zombie(health, speed, damage, name, x, y, ability), ability_charges(ability) {};
	const int getAbiltyCharges() { return this->ability_charges; }
	virtual ~PoleVaultingZombie();
};

