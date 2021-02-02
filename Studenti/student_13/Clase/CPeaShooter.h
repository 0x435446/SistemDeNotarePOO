#pragma once
#include "CPlant.h"

class CPeaShooter :
	public CPlant
{
public:
	CPeaShooter(int difficulty, UserInterface::CField& game, int line, int column, char type) :CPlant(difficulty, game, line, column, type) { ; }
	


};

