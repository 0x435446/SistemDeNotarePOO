#pragma once
#include "Plant.h"
#include <fstream>
class WallNut :public Plant
{
public:
	WallNut(int, int);
	~WallNut() { ; }
	int getSuns() { return 0; }
	void executeFunction() { this->draw(); }
	void draw();
private:

};

