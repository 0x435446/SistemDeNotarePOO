#pragma once
#include  <iostream>
#include <fstream>
#include <chrono>
#include "IDrawable.h"
class PeaShooter;
class Zombie;
class Pea;
class Entity : IDrawable
{
public:
	Entity(int x, int y, std::string glyph);
	virtual ~Entity();
	virtual void interactWith(Zombie &e) = 0;
	virtual void interactWith(PeaShooter &e) = 0;
	virtual void interactWith(Pea &e) = 0;
	virtual void interact(Entity &e) = 0;
	virtual int getX();
	virtual int getY();
	virtual std::string getGlyph();
	virtual void setX(int x);
	virtual void setY(int y);
	virtual void setGlyph(std::string glyph);
	virtual std::chrono::time_point<std::chrono::system_clock> getTimer();
	virtual void setTimer(std::chrono::time_point<std::chrono::system_clock> timer);
	virtual int getMovement();
	virtual bool getSpecial();
protected:
	std::ofstream outFile;
	int x;
	int y;
	std::string glyph;
	std::chrono::time_point<std::chrono::system_clock> actionTimer;
	int movement;
	bool special;
};

