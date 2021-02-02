#pragma once
#include "Plant.h"
#include "IDrawable.h"
class BattleTile : public IDrawable
{
public:
	BattleTile(int, int);
	void draw();
	bool isOccupied() { return occupied; }
	Plant* getPlant() { return plant; }
	void addPlant(Plant* p) { occupied = true; plant = p; }
	void removePlant() { occupied = false; delete plant; plant = nullptr; }
	int getY() const { return startY; }
	bool pressedInside(int,int);
	bool getSuns(int,int);
private:
	bool occupied;
	Plant* plant;
};

