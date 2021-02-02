#pragma once

class buget
{
	static buget* valoare;
	int bani = 0;
	buget() {};
	buget(const buget&) {};

public:
	static buget &getBuget();
	void setBani(int i);
	int getBani();
	void addBani(int i);
	buget& operator= (const buget& C);
	buget operator+ (int k);
	~buget() {};
};

