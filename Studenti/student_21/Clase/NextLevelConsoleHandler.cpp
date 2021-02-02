#include "NextLevelConsoleHandler.h"
#include <windows.h>
#include <iostream>

ConsoleHandlerV2& ConsoleHandlerV2::getInstance()
{
	_instanceCount++;
	if (_instance == nullptr)
	{
		_instance = new ConsoleHandlerV2;
	}
	return *_instance;
}
void ConsoleHandlerV2::releaseInstance()
{
	_instanceCount--;
	if (_instanceCount == 0 && _instance != nullptr)
	{
		delete _instance;
		_instance = nullptr;
	}
	return;
}

ConsoleHandlerV2::ConsoleHandlerV2()
{
	Init();
}
ConsoleHandlerV2::~ConsoleHandlerV2() {}

int ConsoleHandlerV2::Init()
{
   
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    hNewScreenBuffer = CreateConsoleScreenBuffer(
        GENERIC_READ |           
        GENERIC_WRITE,
        FILE_SHARE_READ |
        FILE_SHARE_WRITE,       
        NULL,                   
        CONSOLE_TEXTMODE_BUFFER, 
        NULL);                 
    if (hStdout == INVALID_HANDLE_VALUE ||
        hNewScreenBuffer == INVALID_HANDLE_VALUE)
    {
        printf("CreateConsoleScreenBuffer failed - (%d)\n", GetLastError());
        return 1;
    }


    if (!SetConsoleActiveScreenBuffer(hNewScreenBuffer))
    {
        printf("SetConsoleActiveScreenBuffer failed - (%d)\n", GetLastError());
        return 1;
    }

  

    srctReadRect.Top = 0;  
    srctReadRect.Left = 0;
    srctReadRect.Bottom = 41; 
    srctReadRect.Right = 154;


    coordBufSize.Y = 42;
    coordBufSize.X = 155;

    coordBufCoord.X = 0;
    coordBufCoord.Y = 0;

    srctWriteRect.Top = 0; 
    srctWriteRect.Left = 0;
    srctWriteRect.Bottom = 41;
    srctWriteRect.Right = 154;
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); 

    MoveWindow(console, r.left, r.top, 1280, 720, TRUE);
    SetWindowLong(GetConsoleWindow(), GWL_STYLE, GetWindowLong(GetConsoleWindow(), GWL_STYLE) & ~WS_SIZEBOX & ~WS_MAXIMIZEBOX);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(hStdout, &info);
    COORD new_size = { info.srWindow.Right - info.srWindow.Left + 1, info.srWindow.Bottom - info.srWindow.Top + 1 };
    SetConsoleScreenBufferSize(hStdout, new_size);
}
void ConsoleHandlerV2::updateConsoleBuffer(char pixel, int color, int x, int y)
{
    int vPos = y * 155 + x;
    if (vPos < 6510)
    {
        chiBuffer[vPos].Char.UnicodeChar = pixel;
        chiBuffer[vPos].Attributes = color;
    }
}
void ConsoleHandlerV2::Draw()
{
    fSuccess = WriteConsoleOutput(
        hNewScreenBuffer, 
        chiBuffer,       
        coordBufSize,   
        coordBufCoord,   
        &srctWriteRect); 
    if (!fSuccess)
    {
        printf("WriteConsoleOutput failed - (%d)\n", GetLastError());
        return;
    }
}

void ConsoleHandlerV2::reset()
{
    for (int i = 0; i < 42; i++)
    {
        for (int j = 0; j < 155; j++)
        {
            chiBuffer[i*155 + j].Char.UnicodeChar = 32;
            chiBuffer[i*155 + j].Attributes = 15;
        }
    }
}

ConsoleHandlerV2* ConsoleHandlerV2::_instance = nullptr;
int ConsoleHandlerV2::_instanceCount = 0;