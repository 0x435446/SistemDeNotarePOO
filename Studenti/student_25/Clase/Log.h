#pragma once
#include <string>
class Log
{
private:
	static std::string fisier;
public:
	Log();
	~Log();

	static void logare(std::string);
};


