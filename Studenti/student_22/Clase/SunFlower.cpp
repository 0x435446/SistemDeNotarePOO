#include "SunFlower.h"
#define special_power 0.2f


SunFlower::SunFlower(int pozX, int pozY): Plant(pozX, pozY)
{
	activate = true;
}


SunFlower::~SunFlower()
{
}

std::string SunFlower::getAttackingType()
{
	if (activate) {
		activate = false;
		return "sun";
	}
	return "non";
}

//void SunFlower::special(PooVsZom * e)
//{
//	if (!activate) {
//		e->setSunTime(e->getSunTime() - special_power);
//		activate = true;
//	}
//	
//}
