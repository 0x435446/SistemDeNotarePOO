#pragma once

#include<iostream>

using namespace std;

class iZombie
{
private:
public:
	iZombie() { ; }
	~iZombie() { ; }

	virtual void SetxPos(int x)=0;

	virtual void SetyPos(int y)=0;

	virtual int GetxPos()=0;

	virtual int GetyPos()=0;

	virtual int GetSpeed() = 0;

	virtual int GetHealth() = 0;

	virtual void ReduceHealth(int reduce) = 0;

	virtual char GetSymbol() = 0;

};
