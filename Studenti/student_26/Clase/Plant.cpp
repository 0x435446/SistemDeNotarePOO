#include "Plant.h"
#include "Zombie.h"

Plant::Plant(int HitPoints, int AttackDamage, int AttackSpeed, int Cost, wchar_t cSign, COORD Center) :Entity(HitPoints, AttackDamage, AttackSpeed), Drawable(cSign, Center), Cost(Cost)
{
}

Plant::~Plant()
{
}

void Plant::fightWith(Panel& panel, Zombie& zombie)
{
	//Zombie Vs Planta

	//Daca intalneste planta se opreste sa atace
	zombie.setMvSpeed(0);

	//scade hp-ul plantei
	this->HitPoints -= zombie.getAD();
	if (this->HitPoints <= 0)
		this->Erase(panel);

	//Daca planta e moarta zombie isi continua miscarea
	if (this->HitPoints <= 0)
		zombie.setMvSpeed(50);
}