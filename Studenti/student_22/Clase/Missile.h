#pragma once
#include "Entity.h"


class Missile :
	public Entity
{
public:
	Missile(int pozX, int pozY, bool isMoving, short int movement);
	~Missile();
	float getSpecial();
	void specialSetPozX(float pozX);
	void specialSetPozY(float pozY);
protected:
	float specialEfect;

};

