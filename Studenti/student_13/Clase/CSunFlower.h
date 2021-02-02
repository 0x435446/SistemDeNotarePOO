#pragma once
#include "CPlant.h"
class CSunFlower :
	public CPlant
{
public:
	CSunFlower(int difficulty, UserInterface::CField& game, int line, int column, char type) :CPlant(difficulty, game, line, column, type) { ; }

};

