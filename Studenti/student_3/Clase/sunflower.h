#pragma once
#include "plants.h"
#include "zombie.h"
class sunflower :
	virtual public plants
{
	int valoare = 25;
	static int numarSunflower;
public:
	static int getNrSunflower() {return sunflower::numarSunflower;}
	bool getActiv() { return this->activ; }
	sunflower(int, int);
	void drawSunflower(int, int);
	void deleteSunflower(int, int)override;
	virtual int fightWith(std::string nume, int life);
	virtual std::string getNume() { return this->nume; };
	~sunflower();
};

