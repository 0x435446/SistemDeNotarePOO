#include "Log.h"

Log::Log()
{
}

void Log::adaug_mesaj(std::string mesaj)
{
	std::string file_location ="log.txt";
	std::ofstream f(file_location,std::fstream::app);
	f << mesaj.c_str() << "\n";
}


Log::~Log()
{
}
