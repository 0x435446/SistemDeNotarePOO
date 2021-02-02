#pragma once
#include <ostream>
#include "ConsoleOutput.h"

class Entity
{
protected:
	int x;
	int y;
	char ch = '?';

	bool movable;
	bool hasNormalPeas;

	double life;
	double dmg;
public:

	Entity(const unsigned int&, const unsigned int&, char);
	virtual void attack() = 0;
	virtual void move() = 0;
	char showSymbol();
	int posX() const { return x; };
	int posY() const { return y; };
	bool isAlive();
	bool isMoovable() const { return movable; };
	double getDmg() const { return dmg; };
	bool  doesHaveNormalPeas() const { return hasNormalPeas; };
	void damage(const double&);
	friend std::ostream& operator<< (std::ostream& out, const Entity& entity)
	{
		out << entity.ch;
		return out;
	}
	friend UserInterface::ConsoleOutput& operator<< (UserInterface::ConsoleOutput& out, const Entity& entity)
	{
		out << entity.ch;
		return out;
	}
	~Entity();
};

