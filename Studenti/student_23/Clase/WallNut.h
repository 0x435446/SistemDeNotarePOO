#pragma once
#include "Plant.h"
class WallNut :
	private Plant
{
public:
	WallNut(int X, int Y);

	void setHealth(int viata);
	void setCost(int pret);
	void setShootspeed(int speed);
	void setCoords(int X, int Y);
	void setDamage(int damage);
	void setSpecialEffect(int efect_special);
	void setLook(char caracter);

	int getHealth();
	int getCost();
	int getShootSpeed();
	int getX();
	int getY();
	int getDamage();
	int getSpecialEffect();
	char getLook();

private:
	int health, cost, coordX, coordY, shootspeed, projectileDamage;
	int specialEffect;
	char look;
};


