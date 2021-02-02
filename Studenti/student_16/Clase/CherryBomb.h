#pragma once
#include "Plant.h"
#include <fstream>
class CherryBomb :public Plant
{
public:
	CherryBomb(int, int);
	~CherryBomb() { ; }
	void executeFunction();
	void draw();
	int getSuns() { return 0; }
private:

};

