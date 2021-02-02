#pragma once
#include "Zombie.h"
class PoleVaultingZombie : public Zombie
{
public:
	PoleVaultingZombie(int, int);
	~PoleVaultingZombie() { ; }
	void draw();
	void executeFunction();
private:
	
};

