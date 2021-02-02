#pragma once
#include"CPlant.h"

class CSunflower: public CPlant  //ascii 64
{
public:
	CSunflower(const int& speed,const int& type, const int& cost, const int& maxBites);
	void drawEntity(int row,int col);
	int getValue();
	int getMaxBites();
	int getAscii();
	int getSpeed();
	void reduceHealth(int val);
	~CSunflower();
};

