#pragma once
#include "Sprite.h"
#include <string>
#define MOVING_PART 0x0001
#define ONE_TIME_DRAWING 0x0002

class Entity
{
public:
	Entity();
	Entity(float pozX, float pozY, bool isMoving, short int movement);
	virtual ~Entity();
	float getPozX();
	float getPozY();
	float getLastPozX();
	float getLastPozY();
	short int getMovement();
	bool getIsMoving();
	bool getIsDead();
	void setIsMoving(bool isMoving);
	void setIsDead(bool isDead);
	void setPozX(float pozX);
	void setPozY(float pozY);
	std::string getTag();
	void setTag(std::string tag);
	Sprite sprite;
	double getMovingSpeed();
protected:
	float pozX;
	float pozY;
	float lastPozX;
	float lastPozY;
	bool isMoving;
	//folosit pentru directia in care se misca entitatea, -1 pt de la dreapat catre stanga si 1 pt invers
	short int movement;
	double movingSpeed;
	bool isDead;
	std::string tag;
};

