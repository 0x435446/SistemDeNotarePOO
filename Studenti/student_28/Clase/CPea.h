#pragma once
#include"CProiectil.h"

class CPea: public CProiectil            //ascii 249
{
public:
	CPea(const int& movingspeed, const int& damageDealt, const int& speed, const int& type);
	int getValue();
	int getMaxBites();
	int getAscii() { return m_type; }
	int getSpeed() { return m_speed; }
	void drawEntity(int row,int col);
	int getMovingSpeed() { return m_movingspeed; }
	void reduceHealth(int val);
	~CPea();
};

