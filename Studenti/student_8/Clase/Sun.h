#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <time.h>
#include <chrono>
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
using namespace std::chrono;
using namespace std;
class Sun
{
private :
	
	int x, y;
	unsigned int valoare;
	int aparut;
	
public:
	time_point<steady_clock> timer = steady_clock::now();
	Sun(int i);
	Sun();
	~Sun();
	void write();
	void unwrite();
	
	int cursor(string buff);
	static void verifAfisare(Sun Sun[],int interval);
	friend ostream& operator<<(ostream& os, Sun const & tc) 
	{
		return os << tc.x <<" "<< tc.y<<" " <<tc.valoare<<" " <<endl;
	
	}
};

