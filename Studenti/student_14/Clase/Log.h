#pragma once

#include <time.h>
#include <chrono>
#include <Windows.h>
#include <string>

class Log
{
private:
	std::string jucator;
public:
	Log();
	~Log() {};
	void log_in();
	std::string get_player_name() { return this->jucator; }
	WORD GetConsoleTextAttribute(HANDLE hCon);
};

