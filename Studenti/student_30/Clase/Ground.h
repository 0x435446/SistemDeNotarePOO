#pragma once
#include "Entity.h"
#include "ConsoleOutput.h"
#include "Zona.h"
#include <vector>



class Ground :
	public Entity
{
protected:
	std::vector<Zona*> vect;
	int x, y;
public:
	Ground();
	Ground(int a, int b);
	void update(std::string action);
	~Ground();
	void draw();
	void set_position(int a, int b);
};

