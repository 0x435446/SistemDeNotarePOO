#include "ShopPlants.h"



ShopPlants::ShopPlants()
{
}

ShopPlants::ShopPlants(const std::string name, int cost, const int x, const int y)
{
	this->name = name;
	this->cost = cost;
	this->x = x;
	this->y = y;
}


ShopPlants::~ShopPlants()
{
}
