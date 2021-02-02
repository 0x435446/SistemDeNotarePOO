#pragma once
#include <fstream>
class Log
{
	static Log * instance;
	Log() {};
public:
	static Log& getInstance();
	void destroyInstance();

	void displayMessage(const char *);

	bool isEmpty(std::ifstream&);
	~Log() {};

};

