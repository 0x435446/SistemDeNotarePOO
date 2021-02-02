#pragma once
#include "Entity.h"
#include<vector>
#include "Zona.h"
class Scor :
	public Entity
{
protected:
	int x, y;
	int valoare;
	std::vector<Zona*>vect;
	
public:
	Scor();
	Scor(int, int);
	~Scor();
	void draw();
	void update(std::string);
	void set_valoare();
	static Scor * getInstance();
	static Scor* instance;
};

