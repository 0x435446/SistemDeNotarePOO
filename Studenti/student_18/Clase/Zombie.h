#pragma once
#include"Drowable.h"
class Zombie :public Drowable
{
	static time_t nextZombie;
	static const unsigned period = 10;
protected:
	unsigned speed,health;
	time_t nextMove;
public:
	Zombie(const unsigned& row, const unsigned& col, const std::string& shape, const unsigned& speed,const unsigned& health);
	virtual ~Zombie() {}
	static void set_nextZombie(const time_t& time) { nextZombie = time; }
	static time_t get_nextZombie(){ return nextZombie; }
	static unsigned getPeriod(){ return period; }
	void printEntity()const override final;
	void clearEntity()const override final;
};
