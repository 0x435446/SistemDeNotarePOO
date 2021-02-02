#include "SunFlower.h"

SunFlower::SunFlower() : m_increaseSunRate(INCREASE_SUN_RATE)
{
	this->SetType(SunFlowerType);
	this->SetCost(SUNFLOWER_COST);
}

SunFlower::~SunFlower()
{
}

int SunFlower::GetIncreaseSunRate() const
{
	return this->m_increaseSunRate;
}