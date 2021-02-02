#pragma once
#include<vector>
#include"CEntity.h"

class CResurse: public CEntity                 //ascii 167
{
	int m_value;
public:
	CResurse(int value, int speed, int type = 0);
	void drawEntity(int row,int col);
	void drawSun(int value);
	void changeSpeed(int number);
	int getValue();
	int getAscii() { return this->m_type; }
	int getSpeed() { return this->m_speed; }
	bool isResurse() { return true; }
	bool isPlant() { return false; }
	bool isZombie() { return false; }
	bool isProiectil() { return false; }
	int getMaxBites();
	int getMovingSpeed() { return 0; }
	void reduceHealth(int val);
	~CResurse() {};
};

