#pragma once
#include "CoreObject.h"
class Peashooter :public CoreObject
{
	public:
		Peashooter();
		~Peashooter();
		void setPosition(int x, int y);
		int getX();
		int getY();
		int getCost();
	private:
		 int x, y;

};

