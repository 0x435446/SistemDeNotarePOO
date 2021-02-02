#pragma once
#include <string>
#include <windows.h>

namespace UserInterface
{
	class ConsoleInput
	{
	private:
		static ConsoleInput* console;
		HANDLE hStdin;
		DWORD cNumRead, fdwMode, i;
		INPUT_RECORD irInBuff[128];

	public:
		ConsoleInput();
		~ConsoleInput();

		static ConsoleInput& getInstance();
		static void destroyInstance();

		std::string getMouseEvent();
		unsigned char getChar();
	};
}

