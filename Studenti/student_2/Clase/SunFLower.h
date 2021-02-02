#pragma once
#include"Plant.h"
class SunFlower: public Plant
{private:

	const int resurse = 50;
public:
	SunFlower() : Plant() {}
	SunFlower(int x, int y);
	void print(int x, int y) override;
	~SunFlower();
};

