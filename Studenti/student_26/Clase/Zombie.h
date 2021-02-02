#pragma once
#include "Entity.h"
#include "Drawable.h"
#include "IZombie.h"
#include <chrono>
#include <time.h>
class Zombie :
	public Entity, public Drawable, public IZombie
{
protected:
	int MvSpeed;
	int nFrameCount = 0;
	std::chrono::time_point<std::chrono::steady_clock> StartMove = std::chrono::high_resolution_clock::now();
	std::chrono::time_point<std::chrono::steady_clock> StartAttack = std::chrono::high_resolution_clock::now();
public:
	Zombie(int HitPoints, int AttackDamage, int AttackSpeed, int MovementSpeed, wchar_t cSign, COORD Center);
	~Zombie();
	//Get
	int& getMvSpeed() { return this->MvSpeed; }
	//Set
	void setMvSpeed(int MovementSpeed) { this->MvSpeed = MovementSpeed; }
	//The Collision
	void fight(Panel& panel, Entity& e) override { e.fightWith(panel,*this); }
	//Fighting
	virtual void fightWith(Panel&, Plant&)  override;
	virtual void fightWith(Panel&, Zombie&) override {}
	//Behavior
	virtual bool Draw(Panel&) = 0;
	virtual bool Erase(Panel&) = 0;
	//Zombie
	virtual void Move(Panel&);
	virtual void Attack(Panel&, Plant&)override;
};

