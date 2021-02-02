#pragma once
#include"CEntity.h"

class CProiectil: public CEntity
{
protected:
	int m_damageDealt;
	int m_movingspeed;
public:
	CProiectil(const int& movingspeed,const int& damageDealt,const int& speed, const int& type);
	bool isResurse() { return false; }
	bool isPlant() { return false; }
	bool isZombie() { return true; }
	bool isProiectil() { return true; }
	~CProiectil();
};

