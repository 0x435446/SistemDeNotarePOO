#define _CRT_SECURE_NO_WARNINGS
#include "Log.h"
#include<stdio.h>
#include<stdlib.h>

Log *Log::instance = nullptr;

Log::Log()
{
}

Log::Log(const Log &other)
{
}

Log &Log::get_instance()
{
	if (!Log::instance)
	{
		Log::instance = new Log();
	}
	return *Log::instance;
}

void Log::destroy_instance()
{
	if (Log::instance)
	{
		delete Log::instance;
		Log::instance = nullptr;
	}
}

void Log::logevent(const char *msg)
{
	FILE *f = fopen("log.txt", "a");
	fprintf(f, "%s\n", msg);
}

Log::~Log()
{
}
