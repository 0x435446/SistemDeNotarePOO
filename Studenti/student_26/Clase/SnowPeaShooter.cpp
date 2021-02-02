#include "SnowPeaShooter.h"
#include"Zombie.h"
using namespace std::chrono;

void SnowPeaShooter::Shoot(Panel& panel, Zombie& zombie)
{
	COORD Center = this->getCenterOfDrawing(); //de la pozitia initiala a plantei
	auto end = high_resolution_clock::now();
	if (duration_cast<milliseconds>(end - this->Start).count() > this->AttackSpeed)
	{
		this->Start = end;
		if (Center.X < zombie.getCenterOfDrawing().X && Center.Y == zombie.getCenterOfDrawing().Y)
		{
			Shot* newshot = new ShotFrozenPea(Center);//se creeaza un shot
			ShotList.push_back(newshot); //se adauga shot ul la lista
		}
	}
	MoveShots(panel, zombie);//se muta shoturile existente
}

void SnowPeaShooter::Ability(Panel& panel)
{
}
