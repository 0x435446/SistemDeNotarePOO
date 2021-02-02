#pragma once
#include "IDrawable.h"
#include "Proiectil.h"
class Plant :public IDrawable
{
public:
	virtual void executeFunction() = 0;
	std::string getName() { return name; }
	void reduceSuns() { numberOfSuns--; }
	void reduceResistance() { biteResistance--; }
	int getResistance() const { return biteResistance; }
	virtual int getSuns() = 0;
	int getY() const { return startY; }
	Proiectil* getProjectile() { return bullet; }
	void removeProjectile() { delete bullet; bullet = nullptr; }
protected:
	Proiectil* bullet = nullptr;
	int numberOfSuns;
	int biteResistance;
	std::string name;
};

