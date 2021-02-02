#pragma once
#include "Plant.h"
class Sunflower final: public Plant
{
	static int counter;
public:
	Sunflower(const unsigned int&, const unsigned int&, char);
	void attack() override;
	~Sunflower();
};

