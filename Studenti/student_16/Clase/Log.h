#pragma once
#include <string>
class Log
{
public:
	static Log& getInstance();
	void updateLog(std::string);
private:
	static Log* instance;
	Log() { ; }
	~Log() { ; }


};

