#include "Zombi.h"



Zombi::Zombi(int x,int y) : Zombie(x,y)
{

}
void Zombi::print(int x, int y)
{
	conOut(x, y) << "ZOMBIE ";
}

Zombi::~Zombi()
{
}
