#include "Log.h"
#include <fstream>
using namespace std;
Log* Log::instance = nullptr;
Log& Log::getInstance()
{
	if (!Log::instance)
	{
		Log::instance = new Log;
	}
	return *Log::instance;
}
void Log::updateLog(std::string info)
{
	ofstream fout("log.txt", ios::app);
	fout << info << std::endl;
	fout.close();
}