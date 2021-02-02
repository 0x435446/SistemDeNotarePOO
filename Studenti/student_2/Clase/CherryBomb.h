#pragma once
#include "Plant.h"
class CherryBomb :public Plant
{
public:
	CherryBomb(): Plant() {}
	CherryBomb(int x, int y);
	void print(int a, int b)override;
	~CherryBomb();
};

