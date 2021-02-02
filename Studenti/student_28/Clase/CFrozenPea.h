#pragma once
#include"CProiectil.h"

class CFrozenPea: public CProiectil
{
	int speedTaken;
public:
	//CFrozenPea(const int& damage,const int& speedTaken);
	int getSpeedTaken();
	int getDamage();
	~CFrozenPea();
};

