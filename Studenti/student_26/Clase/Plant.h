#pragma once
#include "Entity.h"
#include "Drawable.h"
#include "IPlant.h"
#include <chrono>
#include <time.h>
#include <list>
class Shot;

class Plant :
	public Entity, public Drawable, public IPlant
{
protected:
	int Cost;
	std::list <Shot*> ShotList;
	std::chrono::time_point<std::chrono::steady_clock> Start = std::chrono::high_resolution_clock::now(); //De cand exista planta
	
public:
	Plant(int HitPoints, int AttackDamage, int AttackSpeed, int Cost, wchar_t cSign, COORD Center);
	~Plant();
	//Get
	const int& getCost()const { return this->Cost; }
	//Set
	void setCost(int Val) { this->Cost = Val; }
	//Fighting
	virtual void fightWith(Panel&, Plant& plant) override {}
	virtual void fightWith(Panel&, Zombie& zombie) override;
	void fight(Panel& panel, Entity& e) override { e.fightWith(panel, *this); }
	//Behavior
	virtual bool Draw(Panel&) = 0;
	virtual bool Erase(Panel&) = 0;
	//Shoot
	virtual void Shoot(Panel&, Zombie&) = 0;
	//Ability
	virtual void Ability(Panel&) = 0;
};

