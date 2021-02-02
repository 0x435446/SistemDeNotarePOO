#include "PoleVaulting_Zombie.h"



PoleVaulting_Zombie::PoleVaulting_Zombie(int x, int y) : Zombie(x, y)
{
}
void PoleVaulting_Zombie::print(int x, int y)
{
	conOut(x, y) << "PoleVaulting";
	conOut(x+1, y) << "Zombie ";
}

PoleVaulting_Zombie::~PoleVaulting_Zombie()
{
}
