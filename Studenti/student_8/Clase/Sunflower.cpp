#include "Sunflower.h"



Sunflower::Sunflower()
{
	this->viata = 50;
	this->cost = 80;
	this->aparut = 0;
	this->x = 0;
	this->y = 0;
	this->damage = 0;
}


Sunflower::~Sunflower()
{
	
}

void Sunflower::doProiectilMove()
{
}



int Sunflower::placePlant(string buff)
{
	string buff1, buff2;
	int ax = 1;
	int ay = 1;
	if (buff != "")
	{
		buff1 = buff.substr(0, 3);
		buff2 = buff.substr(3, 2);

		if (buff1 != "mou" && buff2 != "mo")
		{
			ax = stoi(buff1);
			ay = stoi(buff2);

		}
	}

	conOut(ax, ay) << "S";
	return 0;
}

void Sunflower::getCoordXY(string buff, vector<Sunflower> &vec, int &cost)
{
	string buff1, buff2;
	int ax = 1;
	int ay = 1;
	int sum = 0;
	if (buff != "")
	{
		buff1 = buff.substr(0, 3);
		buff2 = buff.substr(3, 2);

		if (buff1 != "mou" && buff2 != "mo")
		{
			ax = stoi(buff1);
			ay = stoi(buff2);

		}
	}

	if ((ax >= 51 && ax <= 54) && (ay >= 11 && ay <= 14) && cost >=80)
	{
	
		vec.push_back(Sunflower());
		cost = cost - 80;
		

	}

	if ((ax == 63 || ax == 69 || ax == 75 || ax == 81 || ax == 87 || ax == 93 || ax == 99 || ax == 105) && (ay == 12 || ay == 15 || ay == 18 || ay == 21 || ay == 24) && vec.empty()==0)
	{
		if (vec.back().aparut == 0)
		{
			placePlant(buff);
		    vec.back().aparut = 1;
			vec.back().x = ax;
			vec.back().y = ay;
			
		}
	}
}

void Sunflower::verifDeath(vector<Sunflower>& vec)
{
	if(!vec.empty())
	for (int i=0 ;i<vec.size(); ++i)
		if (vec[i].viata <= 0)
		{	
			
			vec.erase(vec.begin()+i);
		
			break;
		}
}

void Sunflower::setProiectile()
{
}

int Sunflower::getX()
{
	return this->x;
}

int Sunflower::getY()
{
	return this->y;
}

int Sunflower::getViata()
{
	return this->viata;
}



void Sunflower::Fight(Entitate & E)
{
	E.FightWith(*this);
}

void Sunflower::FightWith(Zombie & z)
{
	this->viata = this->viata - z.getDamage();
}

void Sunflower::FightWith(Sunflower & z)
{
}

void Sunflower::FightWith(ZombieB & Z)
{
}

void Sunflower::FightWith(PeaShooter & P)
{
}

void Sunflower::FightWith(Proiectil & Pr)
{
}

