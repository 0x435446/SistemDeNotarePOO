#pragma once
#include "IAbility.h"
#include <chrono>
#include <time.h>
class Ability :
	public IAbility
{
public:
	//override
	virtual void Use(Panel&) = 0;
};

