#pragma once
#include <string>



class entity
{
protected:
	std::string nume;
	int lifePoints;
	bool dead;
	bool activ;
	int attackPoints;
	int pos_x, pos_y;
public:
	entity();
	virtual ~entity();
	virtual int fightWith(std::string nume, int life)=0; 
	virtual void deleteSunflower(int, int) = 0;
	virtual void drawSunflower(int, int);
	virtual void setDead() { this->dead = true; }
	virtual bool getDead() { return this->dead; }
	virtual void setActive() { this->activ = false; };
	virtual std::string getNume() = 0;
	virtual void getDamage(int k) { this->lifePoints -= k; }
	virtual int getLife() const{ return this->lifePoints; }
	virtual void setLife(int i) { this->lifePoints = i; }
	virtual int getX(){return this->pos_x;}
	virtual int getY(){return this->pos_y;}
};

