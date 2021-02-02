#include "Proiectil.h"
#include "PeaShooter.h"
#include "Zombie.h"
#include "Sunflower.h"


Proiectil::Proiectil()
{
}

Proiectil::~Proiectil()
{
}
void Proiectil::doProiectilMove()
{
	
		int last = this->x;

		if (duration_cast<milliseconds>(steady_clock::now() - timer).count() >70)

		{
			timer = std::chrono::steady_clock::now();


			conOut(last, this->y) << " ";
			this->x++;
			conOut(this->x, this->y) << "-";
			last++;
		}
			if (this->viata < 1 )
			{
				conOut(last, this->y) << " ";
				this->damage = 0;
				
			}
		


}

int Proiectil::verifDestroy()
{
	if (this->x > 115 || this->viata <= 0)
	{
		conOut(this->x, this->y) << " ";
		conOut(this->x+3, this->y) << " ";
		return 1;
	}
	return 0;
}

int Proiectil::getX()
{
	return this->x;
}

int Proiectil::getY()
{
	return this->y;
}

void Proiectil::Fight(Entitate & E)
{
	E.FightWith(*this);
}

void Proiectil::FightWith(Zombie & z)
{

	this->viata = -1;
	verifDestroy();
}

void Proiectil::FightWith(Sunflower & z)
{
}

void Proiectil::FightWith(ZombieB & Z)
{
}

void Proiectil::FightWith(PeaShooter & P)
{
}

void Proiectil::FightWith(Proiectil & Pr)
{
}



