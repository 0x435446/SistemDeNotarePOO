#pragma once
#include "IDrawable.h"
#include "Plant.h"
#include <fstream>
#define REACHED_HOUSE 7
class Zombie :public IDrawable
{
public:
	Zombie(int,int,std::string);
	virtual void draw();
	virtual void executeFunction();
	int getY() const { return startY; }
	int getPoints() const { return points; }
	void setEating() { eating = true; }
	void eat(Plant*);
	std::string getName() { return name; }
	bool isExecuted() { return executed; }
	void resetEating() { eating = false; }
	bool isEating() { return eating; }
	void modifyHitpoints(int amount) { hitpoints -= amount; }
	int getHipoints() const { return hitpoints; }
	virtual ~Zombie();
protected:
	steady_clock::time_point eatClock;
	bool eating = false;
	int hitpoints;
	int points;
	std::string name;
	bool executed = false;
};

