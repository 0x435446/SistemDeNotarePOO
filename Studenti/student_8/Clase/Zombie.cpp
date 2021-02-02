#include "Zombie.h"
#include <time.h>
#include <chrono>
#include<string>
#include "ConsoleOutput.h"
#include <thread>
#include "PeaShooter.h"
#include "Proiectil.h"
#include "Sunflower.h"
using namespace std::chrono;


int Zombie::getX()
{
	return this->x;
}

int Zombie::getY()
{
	return this->y;
}

void Zombie::setSpeed(int i)
{
	this->speed = i;
}

int Zombie::getDamage()
{
	return this->damage;
}

Zombie::Zombie()
{
	this->viata = 100;
	this->x = 0;
	this->y = 0;
	this->speed = 1;
	this->damage = 10;
}
Zombie::~Zombie()
{

}
int Zombie::doZombieMove()
{
	int last = this->x;
	if (duration_cast<seconds>(steady_clock::now() - timer).count() >speed/2 )

	{
		timer = std::chrono::steady_clock::now();

		conOut(last, this->y) << " ";
		this->x--;
		conOut(this->x, this->y) << "*";
		last--;
	}
	if (this->viata < 1)
	{
			conOut(last, this->y) << " ";
			return 0;
		}
	
	return 1;
}
void Zombie::Fight(Entitate & E)
{
	E.FightWith(*this);
}
void Zombie::FightWith(Zombie & z)
{
}
void Zombie::FightWith(Sunflower & z)
{
}
void Zombie::FightWith(ZombieB & Z)
{
}
void Zombie::FightWith(PeaShooter & P)
{
	this->speed = 10000;
}
void Zombie::FightWith(Proiectil & Pr)
{
	this->viata = this->viata - Pr.damage;
}
Zombie::Zombie(int start_x,int start_y)
{
	this->viata = 100;
	this->x = start_x;
	this->y = start_y;
	this->speed = 1;
	this->damage = 10;
}


