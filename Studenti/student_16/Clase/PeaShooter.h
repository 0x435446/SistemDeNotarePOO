#pragma once
#include "Plant.h"
#include "Proiectil.h"
#include <fstream>
class PeaShooter :public Plant
{
public:
	PeaShooter(int, int);
	~PeaShooter() { ; }
	void executeFunction();
	void draw();
	int getSuns() { return 0; }
private:
};

