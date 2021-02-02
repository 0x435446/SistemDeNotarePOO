#pragma once
#define _WIN32_WINNT 0x0500
#include <iostream>
#include <windows.h>
#include <mmsystem.h>

class SetConsole final
{
	static SetConsole* instance;
	SetConsole();
	~SetConsole();
	SetConsole(const SetConsole&);
public:
	static SetConsole& getInstance();
	void deleteInstance();
};

