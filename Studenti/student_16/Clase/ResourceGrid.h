#pragma once
#include "IDrawable.h"
#include "Sun.h"
class ResourceGrid :public IDrawable
{
public:
	static ResourceGrid& getInstance();
	~ResourceGrid() { ; }
	void draw();
	void addSun() { resources.push_back(new Sun(this->startX + 2, this->startY + 1 + this->resources.size() * TILE_WIDTH)); money += 1; }
	int getMoney() const { return money; }
	void modifyMoney(int amount);
	void removeSun() { resources.pop_back(); }
private:
	static ResourceGrid* instance;
	ResourceGrid();
	int money;
	std::vector<Sun*> resources;
};