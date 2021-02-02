#pragma once
#include "Entity.h"
#include "Plant.h"
class Sunflower :public Plant,
	public Entity
{
private:

	int price, resistance, grow_time;
	int x, y;


public:
	void set(int price, int resistance, int grow_time) ;
	void ability();
	void draw();
	void shot();
	void uppdate(std::string);
	Sunflower(int a, int b);
	Sunflower();
	~Sunflower();
};

