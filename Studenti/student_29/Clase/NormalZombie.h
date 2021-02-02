#pragma once
#include "Zombie.h"
class NormalZombie final : public Zombie
{
public:
	NormalZombie(const unsigned int&, const unsigned int&, char);
	void attack() override;
	~NormalZombie();
};

