#include <stdio.h>
#include <iostream>
#include <windows.h>
#include "MouseHandler.h"
#include <string>

void ExceptionHandler(const char* s)
{
//	exit(1);
}

MouseHandler& MouseHandler::getInstance()
{
	_instanceCount++;
	if (_instance == nullptr)
	{
		_instance = new MouseHandler;
	}
	return *_instance;
}
void MouseHandler::releaseInstance()
{
	_instanceCount--;
	if (_instanceCount == 0 && _instance != nullptr)
	{
		delete _instance;
		_instance = nullptr;
	}
	return;
}

void MouseHandler::Init()
{
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE)
		ExceptionHandler("GetStdHandle");

	if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
		ExceptionHandler("GetConsoleMode");

	fdwMode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(hStdin, fdwMode))
		ExceptionHandler("SetConsoleMode");

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdin, fdwMode))
		ExceptionHandler("SetConsoleMode");
}

MouseHandler::MouseHandler() : mousePosX(0), mousePosY(0)
{
	Init();
}
MouseHandler::~MouseHandler() {}

void MouseHandler::processInput()
{
	DWORD nr = 0;
	GetNumberOfConsoleInputEvents(hStdin, &nr);
	if (nr)
	{
		if (!ReadConsoleInput(
			hStdin,
			irInBuf,
			128,         
			&cNumRead)) 
			ExceptionHandler("ReadConsoleInput");

		for (i = 0; i < cNumRead; i++)
		{
			switch (irInBuf[i].EventType)
			{
			case MOUSE_EVENT:
			{
				mousePosX = irInBuf[i].Event.MouseEvent.dwMousePosition.X;
				mousePosY = irInBuf[i].Event.MouseEvent.dwMousePosition.Y;
				processedInput = irInBuf[i].Event.MouseEvent.dwEventFlags;
				if (processedInput == 0)
				{
					if (irInBuf[i].Event.MouseEvent.dwButtonState != FROM_LEFT_1ST_BUTTON_PRESSED)
						processedInput = -1;
				}
				return;
			}
			default:
				ExceptionHandler("unknown event type");
				break;
			}
		}
	}
	processedInput = -1;
	return;
}

int MouseHandler::getProcessedInput()
{
	return processedInput;
}

MouseHandler* MouseHandler::_instance = nullptr;
int MouseHandler::_instanceCount = 0;