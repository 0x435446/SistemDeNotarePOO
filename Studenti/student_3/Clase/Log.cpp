#include "Log.h"

Log *Log::instance = nullptr;


Log & Log::getInstance()
{
	if (instance == nullptr)
	{
		instance = new Log;
	}
	return *instance;

}

void Log::destroyInstance()
{
	if (instance != nullptr)
		delete instance;
}

bool Log::isEmpty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

void Log::displayMessage(const char *text)
{

	std::ifstream fin("info.log");

	bool flag = false;

	if (isEmpty(fin))
		flag = true;

	fin.close();

	if (flag)
	{
		std::fstream fout("info.log", std::fstream::out);
		fout << text << std::endl;
		fout.close();
	}
	else
	{
		std::fstream fapp("info.log", std::fstream::app);
		fapp << text << std::endl;
		fapp.close();
	}

}


