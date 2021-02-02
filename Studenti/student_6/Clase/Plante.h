#pragma once
#include<iostream>
#include<string>
#include"Teren.h"
#include"Log.h"

class Plante
{
protected:
	int cost;
	int rezistenta;
public:
	Plante(int, int);
	~Plante();

	 virtual void colectare_plante(Teren, int x,int y)=0;
	 int get_cost()const { return cost; }
};

