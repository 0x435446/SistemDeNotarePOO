#pragma once
#include"Resurse.h"
#include<iostream>
#include<string>
#include"Teren.h"

class Sun:public Resurse
{
public:
	Sun();
	~Sun();

	void set_location(Teren &t,int rate);
	void colectare_sori( Teren,int x,int y);
};

