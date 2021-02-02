#include "ShootingPlant.h"

ShootingPlant::ShootingPlant() : m_speedRate(SHOOTING_SPEED_RATE)
{
}

ShootingPlant::~ShootingPlant()
{
}

int ShootingPlant::GetSpeedRate() const
{
	return this->m_speedRate;
}

void ShootingPlant::SetSpeedRate(const int speed_rate)
{
	this->m_speedRate = speed_rate;
}