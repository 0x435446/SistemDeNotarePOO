#pragma once
#include "IDrawable.h"
#include <fstream>
class Avatar :public IDrawable
{

public:
	void draw();
	int getCost() const { return cost; }
	std::string getName() { return plantName; }
	Avatar(std::string,int,int);
	~Avatar() { ; }
private:
	std::string plantName;
	int cost;
};

