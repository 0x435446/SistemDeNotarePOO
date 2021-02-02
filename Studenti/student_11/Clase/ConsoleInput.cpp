#include <stdio.h>
#include <windows.h>
#include "ConsoleInput.h"
#include <string>
#include"Sunflower.h"
#include"Peashooter.h"
#include"ConsoleOutput.h"
#include"PeaProjectile.h"
#include<thread>
#include"sun.h"
#include"zombie.h"
#include<random>
#include<fstream>
#include<iostream>

using namespace UserInterface;
void ExceptionHandler(const char *s)
{
	// TODO: you should handle this
	exit(1);
}
ConsoleInput::ConsoleInput()
{
	// Get the standard input handle. 
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE)
		ExceptionHandler("GetStdHandle");

	// Save the current input mode, to be restored on exit. 
	if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
		ExceptionHandler("GetConsoleMode");

	// Disable 'Quick Edit Mode' option.
	fdwMode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(hStdin, fdwMode))
		ExceptionHandler("SetConsoleMode");
	
	// Enable the window and mouse input events.
	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdin, fdwMode))
		ExceptionHandler("SetConsoleMode");
}

ConsoleInput::~ConsoleInput()
{
}

ConsoleInput & UserInterface::ConsoleInput::getInstance(void)
{
	// TODO: singleton logics
	ConsoleInput *console = new ConsoleInput();
	return *console;
}
std::string ConsoleInput::mouseEventProc(MOUSE_EVENT_RECORD ir)
{
	static	int x, y, plant_cost, sun_value,random,lovit=0;
	static int score=0,soare=100;
	Sunflower s;
	Peashooter p;
	PeaProjectile a;
	Sun sun;
	zombie Zomb;
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(14, 20);
	random = distr(eng);
	std::thread(&zombie::setPosition, Zomb, random, 69).detach();
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	std::string output = "Mouse event: ";
	switch (ir.dwEventFlags)
	{
	case MOUSE_MOVED:
		output += "mouse moved at (";
		output += std::to_string(ir.dwMousePosition.X);
		output += ", ";
		output += std::to_string(ir.dwMousePosition.Y);
		output += ")";
		return output;
		
	case DOUBLE_CLICK:
		output += "mouse double clicked at (";
		output += std::to_string(ir.dwMousePosition.X);
		output += ", ";
		output += std::to_string(ir.dwMousePosition.Y);
		output += ")             ";
		if (ir.dwMousePosition.X == 48 && ir.dwMousePosition.Y == 10)
		{
			plant_cost = s.getCost();
			if (soare >= plant_cost)
			{
				s.setPosition(ir.dwMousePosition.X, ir.dwMousePosition.Y);
				soare -= plant_cost;
				conOut(10, 15) << "    ";
				conOut(10, 15) << soare;
			}
		}
		if (ir.dwMousePosition.X == 50 && ir.dwMousePosition.Y == 10)
		{
			plant_cost = p.getCost();
			if (soare >=plant_cost)
			{
				p.setPosition(ir.dwMousePosition.X, ir.dwMousePosition.Y);
				x = p.getX();
				y = p.getY();
				std::thread(&PeaProjectile::setPosition, a, x, y).detach();
				int projx, projy;
				projx = a.getX();
				projy = a.getY();
				soare -=plant_cost;
				conOut(10, 15) << "    ";
				conOut(10, 15) << soare;
			}
		}
		if (ir.dwMousePosition.X == 31 && ir.dwMousePosition.Y == 10 || ir.dwMousePosition.X == 33 && ir.dwMousePosition.Y == 10 || ir.dwMousePosition.X == 35 && ir.dwMousePosition.Y == 10 || ir.dwMousePosition.X == 37 && ir.dwMousePosition.Y == 10)
		{
			sun_value = sun.getValue();
			soare+=sun_value;
			conOut(10, 15) << "    ";
			conOut(10,15)<<soare;
			if (ir.dwMousePosition.X == 31)
				conOut(10, 31) << " ";
			else if (ir.dwMousePosition.X == 33)
				conOut(10, 33) << " ";
			else if (ir.dwMousePosition.X == 35)
				conOut(10, 35) << " ";
			else
				conOut(10, 37) << " ";
		

		}
		return output;
	}
	return output;
}
std::string ConsoleInput::resizeEventProc(WINDOW_BUFFER_SIZE_RECORD) { return ""; };
std::string ConsoleInput::keyEventProc(KEY_EVENT_RECORD) { return ""; };

std::string UserInterface::ConsoleInput::getUserActions()
{
	DWORD nr = 0;
	GetNumberOfConsoleInputEvents(hStdin, &nr);
	if (nr)
	{
		if (!ReadConsoleInput(
			hStdin,      // input buffer handle 
			irInBuf,     // buffer to read into 
			128,         // size of read buffer 
			&cNumRead)) // number of records read 
			ExceptionHandler("ReadConsoleInput");

		// Dispatch the events to the appropriate handler. 
		for (i = 0; i < cNumRead; i++)
		{
			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT: // keyboard input 
				return keyEventProc(irInBuf[i].Event.KeyEvent);

			case MOUSE_EVENT: // mouse input 
				return mouseEventProc(irInBuf[i].Event.MouseEvent);

			case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
				return resizeEventProc(irInBuf[i].Event.WindowBufferSizeEvent);

			case FOCUS_EVENT:  // disregard focus events 
				return "";

			case MENU_EVENT:   // disregard menu events 
				return "";

			default:
				ExceptionHandler("unknown event type");
				break;
			}
		}
	}
	
	return "";
}