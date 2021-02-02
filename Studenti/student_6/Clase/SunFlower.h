#pragma once
#include<iostream>
#include<string>
#include"Plante.h"

class SunFlower:public Plante
{
public:
	SunFlower(int,int);
	~SunFlower();

	void colectare_plante(Teren, int, int)override;
	void plaseaza_plante(Teren, int x, int y);
};

