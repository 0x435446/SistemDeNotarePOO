#pragma once
#include <time.h>
#include <chrono>
#include <iostream>
using namespace std::chrono;
class Time
{
private:
	bool set;
	std::chrono::system_clock::time_point now, end;
	int durat;
public:
	Time()
	{
		now = std::chrono::system_clock::now();
	}
	void set_time()
	{
		set = 1;
	}
	void update()
	{
		end = std::chrono::system_clock::now();
		durat = duration_cast<seconds>(end - now).count();
		if (set)
		{
			now = end;
			set = 0;
		}
	}
	int durata()
	{
		return durat;
	}
};