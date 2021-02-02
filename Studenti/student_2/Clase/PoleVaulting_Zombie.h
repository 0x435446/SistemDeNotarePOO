#pragma once
#include "Zombie.h"
class PoleVaulting_Zombie :public Zombie
{
public:
	PoleVaulting_Zombie() :Zombie() {}
	PoleVaulting_Zombie(int x, int y);
	void print(int x, int y)override;
	~PoleVaulting_Zombie();
};

