#pragma once
#include <iostream>
#include "Panel.h"

class Plant;
class Zombie;

class Entity
{
protected:
	int HitPoints;
	int AttackDamage;
	int AttackSpeed;
	
public:
	Entity(int HP, int AD, int AS):HitPoints(HP),AttackDamage(AD),AttackSpeed(AS){}
	//Get
	const int& getHP()const { return this->HitPoints; }
	const int& getAD()const { return this->AttackDamage; }
	const int& getASpeed()const { return this->AttackSpeed; }
	//Set
	void setHP(int HitPoints) { this->HitPoints = HitPoints; }
	void setAD(int AttackDamage) { this->AttackDamage = AttackDamage; }
	void setASpeed(int AttackSpeed) { this->AttackSpeed = AttackSpeed; }
	//Fighting
	virtual void fightWith(Panel&, Plant&) = 0;
	virtual void fightWith(Panel&, Zombie&) = 0;
	virtual void fight(Panel&,Entity& e) = 0;
};

