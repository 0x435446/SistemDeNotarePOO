#include "PeaShooter.h"
#include "Proiectil.h"
#include "Sunflower.h"
#include "Zombie.h"
void PeaShooter::setProiectile()
{
	if (this->aparut == 1)
		if (duration_cast<milliseconds>(steady_clock::now() - timer1).count() > 500)
		{
			timer1 = steady_clock::now();
			ProiectilVector.push_back(Proiectil(this->x, this->y));
		}
	      if(!ProiectilVector.empty())
			if (ProiectilVector.front().verifDestroy())
			{
				timer2 = steady_clock::now();
				ProiectilVector.erase(ProiectilVector.begin());
			}

}
int PeaShooter::getFirstProiectilX()
{
	return ProiectilVector.front().getX();
}
int PeaShooter::getFirstProiectilY()
{
	return ProiectilVector.front().getY();
}
int PeaShooter::verifProiectile()
{
	if (!ProiectilVector.empty())
		return 1;
	else
		return 0;
}
int PeaShooter::getY()
{
	return this->y;
}
int PeaShooter::getX()
{
	return this->x;
}
int PeaShooter::getViata()
{
	return this->viata;
}
Proiectil PeaShooter::getFirstProiectil()
{
	return ProiectilVector.front();
}

void PeaShooter::doProiectilMove()
{
	for (int i = 0; i < ProiectilVector.size(); ++i)
	{
		ProiectilVector[i].doProiectilMove();
	}
}

void PeaShooter::Fight(Entitate & E)
{
	E.FightWith(*this);
}

void PeaShooter::FightWith(Zombie & z)
{
	this->viata = this->viata - z.getDamage();

}

void PeaShooter::FightWith(Sunflower & z)
{
}

void PeaShooter::FightWith(ZombieB & Z)
{
}

void PeaShooter::FightWith(PeaShooter & P)
{
}

void PeaShooter::FightWith(Proiectil & Pr)
{
}

PeaShooter::PeaShooter()
{
	this->viata = 50;
	this->cost = 50;
	this->aparut = 0;
	this->x = 0;
	this->y = 0;

}
void PeaShooter::getCoordXY(string buff, vector<PeaShooter> &vec, int &cost )
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

	if ((ax >= 51 && ax <= 54) && (ay >= 16 && ay <= 19) && cost >= 50)
	{

		vec.push_back(PeaShooter());
		cost = cost - 50;

	}

	if ((ax == 63 || ax == 69 || ax == 75 || ax == 81 || ax == 87 || ax == 93 || ax == 99 || ax == 105) && (ay == 12 || ay == 15 || ay == 18 || ay == 21 || ay == 24) && vec.empty() == 0)
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
void PeaShooter::placePlant(string buff)
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

	conOut(ax, ay) << "P";
	
}

void PeaShooter::destroyFirstProiectil(vector<Proiectil>&v)
{
	if(!v.empty())
	v.erase(v.begin());

}




PeaShooter::~PeaShooter()
{
}
