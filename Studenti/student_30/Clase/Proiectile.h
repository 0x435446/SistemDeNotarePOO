#pragma once
#include "Entity.h"
#include "Zona.h"
#include<vector>

class Proiectile :
	public Entity
{
protected:
	int x, y;
public:
	Proiectile();
	Proiectile(int, int);
	~Proiectile();
	void update(std::string) {}
	virtual void move() = 0;
	void draw() {}
};

