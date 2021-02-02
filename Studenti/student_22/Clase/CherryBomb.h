#pragma once
#include "Plant.h"
#define base_damage 3
class CherryBomb :
	public Plant
{
public:
	CherryBomb(int pozX, int pozY);
	~CherryBomb();
	virtual std::string getAttackingType();
	int const damage = base_damage;
};

