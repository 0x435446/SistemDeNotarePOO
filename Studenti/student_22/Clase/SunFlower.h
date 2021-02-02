#pragma once
#include "Plant.h"


class SunFlower :
	public Plant
	
{
public:
	SunFlower(int pozX, int pozY);
	~SunFlower();
	std::string getAttackingType();
	//void special(PooVsZom *e);
private:
	bool activate;
};

