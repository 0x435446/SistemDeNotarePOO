#pragma once
#include "CZombie.h"
class CNormalZombie :
	public CZombie
{
public:
	CNormalZombie();
	CNormalZombie(int difficulty, UserInterface::CField& game, char type) :CZombie(difficulty, game, type) {
		;
	}

	
};

