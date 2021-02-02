#pragma once
#include"CEntities.h"
#include"CEntity.h"
#include"CPlant.h"
#include"CPea.h"

class CPeaShooter: public CPlant          //ascii 147
{
public:
	CPeaShooter(const int& speed, const int& type, const int& cost, const int& maxBites);
	void drawEntity(int row,int col);
	int getAscii() { return this->m_type; }
	int getSpeed() { return this->m_speed; }
	int getValue();
	int getMaxBites();
	void reduceHealth(int val);
	~CPeaShooter() {};
};

