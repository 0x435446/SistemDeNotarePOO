#pragma once
#include "iZombie.h"
class Zombie :
	public iZombie
{
protected:
	int Speed;
	int Health;
	char Symbol;

	int xPos;
	int yPos;

	int LastX;
	int LastY;
public:
	Zombie();
	~Zombie();
	Zombie(int speed, int health,char symbol);

	int GetHealth();

	void ReduceHealth(int reduce);
};

