#pragma once

#include <string>
#include <time.h>
#include <chrono>
#include <Windows.h>


class Sun
{
private:
	int score ;
	float sun_appear_time = 5;
	int v[10] = { 0 };
	static Sun *instance;
public:

	static Sun &getInstance(void);
	const int get_score() { return score; }
	void set_score() { this->score = 100; }
	void buy_plant(int cost) { this->score = this->score - cost; }
	void buy_sunflower();
	void print_score();
	void generate();
	void collect(std::string action);
	WORD GetConsoleTextAttribute(HANDLE hCon);

private:
	Sun();
	~Sun();

};

