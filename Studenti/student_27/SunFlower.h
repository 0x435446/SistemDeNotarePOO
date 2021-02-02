#pragma once
#include "Plant.h"
class SunFlower :
	public Plant
{
private:
	int ReduceTime;
public:
	SunFlower();
	~SunFlower();
	SunFlower(char symbol, int cost);
	SunFlower(char symbol, int cost,int x,int y);
	int CheckForSunFlower(int x, int y);

	int GetxPos();

	int GetyPos();

	char GetSymbol();
};

