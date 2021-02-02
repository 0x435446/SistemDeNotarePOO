#pragma once
#include "Plant.h"
#include "Sun.h"
class Sunflower:public Plant
{
public:
	Sunflower(int, int);
	~Sunflower() { ; }
	std::string getName() { return name; }
	void executeFunction();
	int getSuns() { return numberOfSuns; }
	void draw();
private:
};

