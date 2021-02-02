#pragma once
#include <string.h>
#include <time.h>
#include  <iostream>
using namespace std;
class Log
{
public:
	static Log *getInstance();
	static void destroy();
	void setInfo(string command,string dateadded);
	void writeLog();
	
private:
	static Log *instance;
	string command;
	string datetime;
	Log();
	Log(const Log&);
	~Log();
};
