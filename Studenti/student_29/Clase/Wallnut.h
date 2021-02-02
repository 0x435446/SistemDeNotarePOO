#pragma once
#include "Plant.h"
class Wallnut final : public Plant
{
public:
	Wallnut(const unsigned int&, const unsigned int&, char);
	void attack() override;
	~Wallnut();
};

