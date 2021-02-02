#pragma once
#include<iostream>
#include"ConsoleInput.h"
#include"ConsoleOutput.h"
#include"CException.h"

class CEntities
{
public:
	virtual void drawEntity(int row,int col) = 0;
	virtual int getAscii() = 0;
	virtual int getSpeed() = 0;
	virtual bool isResurse() = 0;
	virtual bool isPlant() = 0;
	virtual bool isZombie() = 0;
	virtual bool isProiectil() = 0;
	virtual int getValue() = 0;
	virtual int getMaxBites() = 0;
	virtual int getMovingSpeed() = 0;
	virtual void reduceHealth(int val) = 0;
};

