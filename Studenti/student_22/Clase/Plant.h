#pragma once
#include "Entity.h"
//#include "PooVsZom.h"
#include <chrono>
class Plant :
	public Entity
{
public:
	Plant(int pozX, int pozY);
	~Plant();
	virtual float getHealth();
	void setHealth(float health);
	virtual std::string getAttackingType();
	float getComeBackAttack();
	//virtual void special(PooVsZom *e);
protected:
	float health;
	float comeBackAttak;

};

