#pragma once
class Monster
{
public:
	virtual void setHealth(int viata) = 0;
	virtual void setSpeed(int speed) = 0;
	virtual void setAttack(int damage) = 0;
	virtual void setCoords(int X, int Y) = 0;
	virtual void setSpecialEffect(int efect_special) = 0;
	virtual void setLook(char caracter) = 0;

	virtual int getHealth() = 0;
	virtual int getSpeed() = 0;
	virtual int getDamage() = 0;
	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual int getSpecialEffect() = 0;
	virtual char getLook() = 0;

};

