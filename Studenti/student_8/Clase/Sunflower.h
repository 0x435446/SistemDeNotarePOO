#pragma once
#include <iostream>
#include "Entitate.h"
#include <vector>
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "PeaShooter.h"
#include "Proiectil.h"
#include "Zombie.h"

using namespace std::chrono;
class Sunflower :public Entitate
{
private:
	unsigned int cost;
	unsigned int viata;
	int x, y;
	int aparut;
	int damage;
public:
	time_point<steady_clock> timer = steady_clock::now();
	time_point<steady_clock> timer1 = steady_clock::now();
	Sunflower();
	~Sunflower();
	void doProiectilMove();
	static int placePlant(string buff);
	static void getCoordXY(string buff,vector<Sunflower> &vec,int &cost);
	static void verifDeath(vector <Sunflower> &vec);
	void setProiectile();
	int getX();
	int getY();
	int getViata();
	virtual void Fight(Entitate &E) ;
	virtual void FightWith(Zombie &z) ;
	virtual void FightWith(Sunflower &z);
	virtual void FightWith(ZombieB &Z);
	virtual void FightWith(PeaShooter &P) ;
	virtual void FightWith(Proiectil &Pr) ;

};

