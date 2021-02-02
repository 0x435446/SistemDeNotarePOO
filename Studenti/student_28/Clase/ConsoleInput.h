#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<chrono>
#include<iostream>
#include<string>
#include<vector>
#include <time.h>
#include<conio.h>
#include<stdlib.h>

/*TODO: singleton*/

namespace UserInterface
{
	class ConsoleInput
	{
	private:
		static ConsoleInput* instance;
		ConsoleInput();
		~ConsoleInput();
		HANDLE hStdin;
		DWORD cNumRead, fdwMode, fdwSaveOldMode, i;
		INPUT_RECORD irInBuf[128];
		std::string mouseEventProc(MOUSE_EVENT_RECORD);
		std::string resizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
		std::string keyEventProc(KEY_EVENT_RECORD);

	public:
		static ConsoleInput & getInstance(void);
		std::string getUserActions();
	};
}


