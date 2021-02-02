#pragma once
#include"CZombie.h"

class CBucketheadZombie: public CZombie                //ascii 157
{
public:
	CBucketheadZombie(const int& movingspeed, const int& health, const int& speed, const int& type);
	void reduceHealth(int val);
	void drawEntity(int row, int col);
	int getAscii();
	int getSpeed();
	int getValue();
	int getMaxBites();
	int getMovingSpeed();
	~CBucketheadZombie();
};

