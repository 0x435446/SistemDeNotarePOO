#pragma once

#include<iostream>

class iPlant
{
public:
	iPlant() { ; }
	~iPlant() { ; }

	virtual int GetxPos()=0;

	virtual int GetyPos()=0;

	virtual char GetSymbol() = 0;
};
