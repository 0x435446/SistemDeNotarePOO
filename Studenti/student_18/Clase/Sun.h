#pragma once
#include"Resources.h"
class Sun:public Resources
{
private:
	static time_t nextSun;
	static unsigned period;
public:
	Sun(const unsigned& row, const unsigned& col);
	static void setPeriod(const unsigned& periode) { period = periode; }
	static unsigned getPeriod() { return period; }
	static void set_nextSun(const time_t& time) { nextSun = time; }
	static time_t get_nextSun() { return nextSun; }
};

