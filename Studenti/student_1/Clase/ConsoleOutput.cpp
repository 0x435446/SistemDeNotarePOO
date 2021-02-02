#include <windows.h>

#include "ConsoleOutput.h"


using namespace UserInterface;


ConsoleOutput* ConsoleOutput::console = nullptr;

ConsoleOutput::ConsoleOutput()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); 

	HWND console = GetConsoleWindow();

	SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	width = GetSystemMetrics(SM_CXMAXIMIZED);
	height = GetSystemMetrics(SM_CYMAXIMIZED);

	MoveWindow(console, 0, 0, width, height, TRUE);
	ShowWindow(console, SW_SHOWMAXIMIZED);

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);

	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(handle, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(handle, &cursorInfo);
}

ConsoleOutput::~ConsoleOutput()
{
}

ConsoleOutput& ConsoleOutput::getInstance()
{
	if (console == nullptr)
		console = new ConsoleOutput;

	return *console;
}

void ConsoleOutput::destroyInstance()
{
	if (console != nullptr)
	{
		delete console;
		console = nullptr;
	}
}

ConsoleOutput & UserInterface::ConsoleOutput::operator()(int row, int col)
{
	COORD coord;
	coord.X = col;
	coord.Y = row;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return *this;
}

ConsoleOutput & UserInterface::ConsoleOutput::operator[](int colorCode)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, colorCode);

	return *this;
}