#pragma once
#include <fstream>
#include "IDrawable.h";
class Sun :public IDrawable
{
public:
	Sun(int, int);
	~Sun() { ; }
	void draw();
private:
	int money;
};

