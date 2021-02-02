#pragma once
#include "iPlant.h"
class Plant :
	public iPlant
{protected:
	char Symbol;
	int pCost;
	int xPos;
	int yPos;
public:
	Plant();
	~Plant();
};

