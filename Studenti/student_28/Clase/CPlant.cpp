#include "CPlant.h"



CPlant::CPlant(const int& speed, const int& type, const int& cost, const int& maxBites)
	:CEntity(speed, type), m_cost(cost), m_maxBites(maxBites)
{
}
