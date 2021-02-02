#pragma once
#include"Plant.h"
class Peashooter:public Plant
{
private:
	static time_t nextPlant;
public:
	Peashooter();
	Peashooter(const int& row, const int& col);
};

