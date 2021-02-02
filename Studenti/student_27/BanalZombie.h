#pragma once
#include "Zombie.h"
class BanalZombie :
	public Zombie
{
public:
	BanalZombie();
	~BanalZombie();

	BanalZombie(int speed, int health,char symbol);

	void SetxPos(int x);

	void SetyPos(int y);

	int GetxPos();

	int GetyPos();

	int GetSpeed();

	int GetHealth();

	void ReduceHealth(int reduce);

	char GetSymbol();

};

