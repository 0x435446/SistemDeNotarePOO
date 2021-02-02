#pragma once
#include "Plant.h"
#include "Pea.h"
#include <iostream>
#include <vector>
class Peashooter final: public Plant
{
public:
	Peashooter(const unsigned int&, const unsigned int&, char);
	void attack() override;
	Pea& attackZombie();
	~Peashooter();
};

