#pragma once
#include "Plant.h"
class PeaShooter : public Plant
{

public:
	PeaShooter() : Plant() {}
	PeaShooter(int x, int y);
	void print(int x, int y) override;
	~PeaShooter();
};

