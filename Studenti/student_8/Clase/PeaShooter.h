#pragma once
#include<iostream>

#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <vector>
#include "Entitate.h"

class PeaShooter :public Entitate
{
private: 
	unsigned int cost;
    int viata;
	int x, y;
	int aparut;
	
public:
	vector<Proiectil> ProiectilVector;
	time_point<steady_clock> timer = steady_clock::now();
	time_point<steady_clock> timer1 = steady_clock::now();
	time_point<steady_clock> timer2 = steady_clock::now();
	static void getCoordXY(string buff, vector<PeaShooter> &vec, int &cost);
    static void	placePlant( string buff);
	void destroyFirstProiectil(vector<Proiectil> &v);
	void setProiectile();
	int getFirstProiectilX();
	int getFirstProiectilY();
	int verifProiectile();
	int getY();
	int getX();
	int getViata();
	Proiectil getFirstProiectil();
	void doProiectilMove();
	virtual void Fight(Entitate &E);
	virtual void FightWith(Zombie &z);
	virtual void FightWith(Sunflower &z);
	virtual void FightWith(ZombieB &Z);
	virtual void FightWith(PeaShooter &P);
	virtual void FightWith(Proiectil &Pr);
	PeaShooter();
	~PeaShooter();
};

