#pragma once
#include "entity.h"
#include "Log.h"
#include "ConsoleOutput.h"
#include <string>

class zombie : virtual public entity
{
protected:
	int speed;
	//bool activ;
public:
	zombie(int, int);
	int getX() { return this->pos_x; }
	int getY() { return this->pos_y; }
	void setX(int x) { this->pos_y = x; }
	void deleteSunflower(int, int)override {};
	zombie operator-(int k);
	zombie &operator=(const zombie &);
	bool getDead() { return dead; }
	void setZombieSpeed(int i) { this->speed = i; }
	int getZombieSpeed() { return this->speed; }
	virtual void drawZombie(int, int);
	virtual void stergereZombie(int, int);
	virtual ~zombie();
	virtual int fightWith(std::string nume, int life)override;
	virtual std::string getNume() { return this->nume; }
};

