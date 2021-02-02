#pragma once
#include<iostream>
#include"Zombie.h"

using namespace std;

class BucketHead_Zombie:public Zombie
{

private:

public:
	BucketHead_Zombie();
	~BucketHead_Zombie();

	BucketHead_Zombie(int speed, int health, char symbol);

	void SetxPos(int x);

	void SetyPos(int y);

	int GetxPos();

	int GetyPos();

	int GetSpeed();

	int GetHealth();

	void ReduceHealth(int reduce);

	char GetSymbol();
};

