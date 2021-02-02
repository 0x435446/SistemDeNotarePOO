#pragma once
#include"CEntity.h"

class CZombie: public CEntity
{
protected:
	int m_health;
	int m_movingspeed;
public:
	CZombie(const int& movingspeed,const int& health, const int& speed, const int& type);
	bool isResurse() { return false; }
	bool isPlant() { return false; }
	bool isZombie() { return true; }
	bool isProiectil() { return false; }
	virtual ~CZombie();
};

