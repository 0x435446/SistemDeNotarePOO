#pragma once
#include "Monster.h"
class NormalZombie :
	public Monster
{
public:
	NormalZombie(int X,int Y);

	void setHealth(int viata);
	void setSpeed(int speed);
	void setAttack(int damage);
	void setCoords(int X, int Y);
	void setSpecialEffect(int efect_special);
	void setLook(char caracter);

	int getHealth();
	int getSpeed();
	int getDamage();
	int getX();
	int getY();
	int getSpecialEffect();
	char getLook();



private:
	int health, speed, attack, coordX, coordY;
	int specialEffect;
	char look;

};

