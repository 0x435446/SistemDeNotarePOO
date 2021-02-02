#pragma once
#include<iostream>
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <vector>
#include "Entitate.h"


class Proiectil : public Entitate
{
private:
	int x, y;
	
public:
	int viata = 1;
	int damage = 3;
	time_point<steady_clock> timer = steady_clock::now();
	Proiectil();
	Proiectil(int x,int y):x(x+1) , y(y){}
	~Proiectil();
	void doProiectilMove();
	int verifDestroy();
	int getX();
	int getY();
	virtual void Fight(Entitate &E);
	virtual void FightWith(Zombie &z);
	virtual void FightWith(Sunflower &z);
	virtual void FightWith(ZombieB &Z);
	virtual void FightWith(PeaShooter &P);
	virtual void FightWith(Proiectil &Pr);
};

