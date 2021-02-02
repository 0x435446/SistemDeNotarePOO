#pragma once
#include <iostream>


class ShopPlants
{
	std::string name;
	int cost;
	int x;
	int y;
public:
	ShopPlants();
	ShopPlants(const std::string name, int cost, const int x, const int y);
	const std::string getName() { return this->name; }
	const int getCost() { return this->cost; }
	const int getX() { return this->x; }
	const int getY() { return this->y; }
	~ShopPlants();
};

