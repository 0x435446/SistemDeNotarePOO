#pragma once
#include "Plant.h"
class SnowPea :public Plant
{

public:
	SnowPea() : Plant() {}
	SnowPea(int x, int y);
	void print(int a, int b)override;
	~SnowPea();
};

