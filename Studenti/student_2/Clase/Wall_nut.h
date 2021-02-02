#pragma once
#include "Plant.h"
class Wall_nut :public Plant
{
public:
	Wall_nut() : Plant() {}
	Wall_nut(int x, int y);
	void print(int x, int y)override;
	~Wall_nut();
};

