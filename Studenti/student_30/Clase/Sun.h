#pragma once
#include<Windows.h>
#include<string>
#include "Resurse.h"
class Sun :
	public Resurse
{
private:
	int x, y;
	int valoare_sun;
public:
	Sun();
	Sun(int x, int y);
	~Sun();
	void update(std::string) {}
	void draw();
};

