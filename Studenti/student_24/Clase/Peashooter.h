#pragma once
#include "Plant.h"
#include "Pea.h"
#include "Time.h"
class Peashooter :
	public Plant ,
	public Entity
{
private:
	int x, y;
	int frecv;
	int price, resistance, grow_time;
	
	Time t;
public:
	std::vector <Pea*> shot;
	Peashooter(int a,int b);
	void draw();
	void uppdate(std::string);
	void ability();
	void set(int price, int resistance, int grow_time);
	Peashooter();
	~Peashooter();

};

