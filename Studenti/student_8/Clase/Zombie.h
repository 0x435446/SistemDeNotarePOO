#pragma once
#include <chrono>
#include <time.h>
#include "Entitate.h"
using namespace std::chrono;

class Zombie :public Entitate
{
protected :
	int damage;
	int x, y;
	int viata;
	int speed;
public:
	time_point<steady_clock> timer = steady_clock::now() ;
	int getX();
	int getY();
	void setSpeed(int i);
	int getDamage();
	Zombie();
	Zombie(int start_x,int start_y);
	~Zombie();
	int doZombieMove();
	virtual void Fight(Entitate &E);
	virtual void FightWith(Zombie &z);
	virtual void FightWith(Sunflower &z);
	virtual void FightWith(ZombieB &Z);
	virtual void FightWith(PeaShooter &P);
	virtual void FightWith(Proiectil &Pr);

};
