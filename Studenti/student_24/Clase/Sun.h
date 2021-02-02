#pragma once
#include "Entity.h"
class Sun :
	public Entity
{
private:
	int x;
	int y;
	int bonus;
public:
	Sun();
	Sun(int a, int b);
	~Sun();
	void draw();
	void uppdate(std::string);
};

