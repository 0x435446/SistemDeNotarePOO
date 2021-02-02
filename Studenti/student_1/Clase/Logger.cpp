#include <string>

#include "Logger.h"

using namespace Debugging;

Logger* Logger::instance = nullptr;

Logger::Logger() :out("log.txt")
{
}


Logger::~Logger()
{
	out.close();
}

Logger & Logger::getInstance()
{
	if (!instance)
		instance = new Logger();
	return *instance;
}

void Logger::destroyInstance()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

void Logger::log(std::string str)
{
	time_t timer;
	time(&timer);
	out << timer << " : " << str << "\n";
}

std::ofstream & Debugging::operator<<(std::ofstream & os, time_t& timer)
{
	struct tm ptm;
	localtime_s(&ptm, &timer);
	char buff[64];
	std::strftime(buff, 64, "%d/%m/%Y %H:%M:%S", &ptm);
	os << buff;
	return os;
}
