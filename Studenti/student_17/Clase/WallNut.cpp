#include "WallNut.h"

WallNut::WallNut()
{
	this->SetType(WallNutType);
	this->SetMaxBites(WALLNUT_MAX_BITES);
	this->SetCost(WALLNUT_COST);
}

WallNut::~WallNut()
{
}