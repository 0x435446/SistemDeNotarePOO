#pragma once
#include "Entity.h"
#include <vector>
#include "Parcela.h"
#include "Plant.h"
#include "Sunflower.h"



class Shop:public Entity
{
private:
	
	int x, y;
	int type;
	Shop();
	static Shop*instance;

public:
	int gettype();
	void settype(int);
	std::vector<Plant*> plants;
	std::vector <Parcela*> shop;
	void set(int a, int b);
	static Shop*getinstance();
	~Shop();
	void draw();
	void uppdate(std::string);
};

