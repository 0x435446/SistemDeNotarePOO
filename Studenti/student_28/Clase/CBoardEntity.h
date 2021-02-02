#pragma once
#include"CEntity.h"

class CBoardEntity: public CEntity
{
public:
	CBoardEntity(const int& speed,const int& type);
	void drawEntity(int row, int col) { };
	int getAscii() { return m_type; }
	int getSpeed() { return m_speed; }
	bool isResurse() { return false; }
	bool isPlant() { return false; }
	bool isZombie() { return false; }
	bool isProiectil() { return false; }
	int getValue() { return 0; }
	int getMaxBites() { return 0; }
	int getMovingSpeed() { return 0; }
	void reduceHealth(int val) {  };
	~CBoardEntity();
};

