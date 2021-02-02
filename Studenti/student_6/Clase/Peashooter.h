#pragma once
#include<iostream>
#include<string>
#include"Plante.h"
#include"Pea.h"

class Peashooter:public Plante
{
public:
	Peashooter(int,int);
	~Peashooter();
	
	void colectare_plante( Teren, int,int)override;
	void plaseaza_plante( Teren,int x,int y);
};

