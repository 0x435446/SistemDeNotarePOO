#include "Zombie.h"
#include "Plant.h"
using namespace std::chrono;

Zombie::Zombie(int HitPoints, int AttackDamage, int AttackSpeed, int MovementSpeed, wchar_t cSign, COORD Center) : Entity(HitPoints, AttackDamage, AttackSpeed), MvSpeed(MovementSpeed), Drawable(cSign, Center)
{
}

Zombie::~Zombie()
{
}

void Zombie::Attack(Panel& panel, Plant& plant)
{
	auto end = high_resolution_clock::now();
	if (duration_cast<milliseconds>(end - this->StartAttack).count() > this->getASpeed())
	{
		this->StartAttack = end;
		this->fight(panel, plant);
	}

}

void Zombie::fightWith(Panel& panel, Plant& plant) {
	//Planta Vs Zombie

	//Daca Shot-ul plantei intalneste zombie, acesta isi ia dmg
	this->HitPoints -= plant.getAD();

	if (this->HitPoints <= 0)
	{
		this->Erase(panel);//aici e problema
	}
}

void Zombie::Move(Panel& panel)
{
	if (this->getMvSpeed() != 0)
	{
		COORD Center = this->getCenterOfDrawing();
		auto end = high_resolution_clock::now(); 
		if (duration_cast<milliseconds>(end - this->StartMove).count() > this->getMvSpeed())
		{
			this->StartMove = end;
			this->nFrameCount++;
			if (this->nFrameCount % 9 != 0)
			{
				this->Draw(panel);
			}
			else
			{
				this->Erase(panel);
				Center.X--;
				this->setCenterOfDrawing(Center);
			}
		}
	}
}
