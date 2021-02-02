#include "Zombie.h"




Zombie::Zombie(Casuta* c) : Obiect(c)
{
	this->c = 'Z';
	this->damage = 1;
	this->hp = 6;
}


Zombie::~Zombie()
{
}

void Zombie::scadehp(int d)
{
	this->hp -= d;
	if (this->hp < 0)
		this->hp = 0;
}

int Zombie::loveste(int d)
{
	static int nrbucle = 0;
	if (nrbucle >= d)
	{
		nrbucle = 0;
		return damage;
	}
	else
		nrbucle++;
	return 0;
}

int Zombie::gethp()
{
	return hp;
}

bool Zombie::ajunsLaCasa(int d)
{
	static int nrbucle = 0;
	if (d == nrbucle)
		return true;
	nrbucle++;
	return false;
}