#include <fstream>
#include <time.h>

#include "Log.h"

using namespace std;

string Log::fisier = "log.txt";

Log::Log()
{
}


Log::~Log()
{
}

void Log::logare(std::string s)
{
	ofstream f(fisier, fstream::app);

	f << time(NULL) << " " << s << endl;

	f.close();
}
