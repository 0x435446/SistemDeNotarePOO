#include "Plant.h"

unsigned int Plant::s_plantsIdCounter = 0;

Plant::Plant() : m_plantId(Plant::s_plantsIdCounter), m_type(NoPlantType), m_currentBites(0), m_maxBites(MAX_BITES), m_cost(0)
{
	Plant::s_plantsIdCounter++;
}

Plant::~Plant()
{
}

PlantType Plant::GetType() const
{
	return this->m_type;
}

int Plant::GetCurrentBites() const
{
	return this->m_currentBites;
}

int Plant::GetMaxBites() const
{
	return this->m_maxBites;
}

int Plant::GetCost() const
{
	return this->m_cost;
}

void Plant::SetType(const PlantType type)
{
	this->m_type = type;
}

void Plant::GetBitten()
{
	this->m_currentBites++;
	if (this->m_currentBites >= this->m_maxBites)
		delete this;
}

void Plant::SetMaxBites(const int max_bites)
{
	this->m_maxBites = max_bites;
}

void Plant::SetCost(const int cost)
{
	this->m_cost = cost;
}