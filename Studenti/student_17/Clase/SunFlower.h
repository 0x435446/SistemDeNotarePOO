#pragma once
#include "Plant.h"

#define INCREASE_SUN_RATE 10
#define SUNFLOWER_COST 200

class SunFlower : public Plant
{
public:
	SunFlower();
	~SunFlower();
	int GetIncreaseSunRate() const;
private:
	int m_increaseSunRate;
};