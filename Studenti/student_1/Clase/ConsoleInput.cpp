#include <windows.h>
#include <string>
#include <iostream>

#include "ConsoleInput.h"

using namespace UserInterface;

ConsoleInput* ConsoleInput::console = nullptr;

ConsoleInput::ConsoleInput()
{
	hStdin = GetStdHandle(STD_INPUT_HANDLE);

	if (hStdin == INVALID_HANDLE_VALUE)
		exit(1); 

	fdwMode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(hStdin, fdwMode))
		exit(1);

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdin, fdwMode))
		exit(1);
}


ConsoleInput::~ConsoleInput()
{
}


ConsoleInput& ConsoleInput::getInstance()
{
	if (console == nullptr)
		console = new ConsoleInput;
	return *console;
}

void ConsoleInput::destroyInstance()
{
	if (console != nullptr)
	{
		delete console;
		console = nullptr;
	}
}

unsigned char ConsoleInput::getChar()
{
	DWORD nr = 0;

	GetNumberOfConsoleInputEvents(hStdin, &nr);

	if (nr)
	{
		if (!ReadConsoleInput(hStdin, irInBuff, 128, &cNumRead))
			exit(1);


		if (irInBuff[i].EventType == KEY_EVENT)
			return unsigned char(irInBuff[i].Event.KeyEvent.wVirtualKeyCode);
	}

	return 0;
}

std::string ConsoleInput::getMouseEvent()
{
	DWORD nr = 0;

	GetNumberOfConsoleInputEvents(hStdin, &nr);

	std::string output;

	if (nr)
	{
		if (!ReadConsoleInput(hStdin, irInBuff, 128, &cNumRead))
			exit(1);

		if (irInBuff[i].EventType == MOUSE_EVENT)
		{
			MOUSE_EVENT_RECORD ir = irInBuff[i].Event.MouseEvent;
			if (ir.dwEventFlags == DOUBLE_CLICK)
			{
				output += std::to_string(ir.dwMousePosition.Y);
				output += " ";
				output += std::to_string(ir.dwMousePosition.X);
				return output;
			}
		}
	}

	return " ";
}