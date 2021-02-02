#include "Logger.h"
#include<iostream>
#include<string>
#include <fstream>
using namespace std;
#pragma warning(disable:4996)
Log *Log::instance = nullptr;

Log *Log::getInstance()
{
	if (!Log::instance)
	{
		Log::instance = new Log;

	}
	return Log::instance;

}
void Log::destroy()
{
	if (Log::instance)
	{
		delete Log::instance;
		Log::instance = nullptr;
	}
}
void Log::setInfo(string command,string dateadded)
{
	
	this->command = command;
	this->datetime = dateadded;

}
void Log::writeLog()
{

	ofstream fout("pvz.log", ofstream::app);
	fout << this->command<<this->datetime<<"\n";
	fout.close();

	
}
Log::Log()
{
}


Log::~Log()
{
}
