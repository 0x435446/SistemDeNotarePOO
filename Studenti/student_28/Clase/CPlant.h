#pragma once
#include"CProiectil.h"

class CPlant: public CEntity
{
protected:
	int m_cost;
	int m_maxBites;
public:
	CPlant(const int& speed, const int& type, const int& cost, const int& maxBites);
	bool isResurse() { return false; }
	bool isPlant() { return true; }
	bool isZombie() { return false; }
	bool isProiectil() { return false; }
	int getMovingSpeed() { return 0; }
	virtual ~CPlant() {};
};

