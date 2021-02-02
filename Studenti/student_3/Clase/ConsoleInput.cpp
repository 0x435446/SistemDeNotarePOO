#include <stdio.h>
#include <windows.h>
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "sunManagement.h"
#include "buget.h"
#include "sunflower.h"
#include <string>


using namespace UserInterface;


bool ConsoleInput::flag_sunflower = false;
bool ConsoleInput::flag_peashooter = false;

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
	//pentru a apasa pe elementele soare
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	std::string output = "Mouse event: ";
	switch (ir.dwEventFlags)
	{
	case MOUSE_MOVED:
		output += "mouse moved at (";
		output += std::to_string(ir.dwMousePosition.X);
		output += ", ";
		output += std::to_string(ir.dwMousePosition.Y);
		output += ")              ";
		return output;

	case DOUBLE_CLICK:

		
		//coordonate pentru soare
		//coordonate pentru soare
		//coordonate pentru soare
		//coordonate pentru soare
		//coordonate pentru soare
		//coordonate pentru soare
		if ((ir.dwMousePosition.X > 20 && ir.dwMousePosition.X < 40) && (ir.dwMousePosition.Y > 0 && ir.dwMousePosition.Y < 7)) //&& (sunManagement::getInstance().getVector(0) == 1))
		{
			sunManagement::getInstance().deleteSun(0);
			buget::getBuget().addBani(25);
		}
		if ((ir.dwMousePosition.X > 40 && ir.dwMousePosition.X < 60) && (ir.dwMousePosition.Y > 0 && ir.dwMousePosition.Y < 7))// && (sunManagement::getInstance().getVector(1) == 1))
		{
			sunManagement::getInstance().deleteSun(1);
			buget::getBuget().addBani(25);
		}
		if ((ir.dwMousePosition.X > 60 && ir.dwMousePosition.X < 80) && (ir.dwMousePosition.Y > 0 && ir.dwMousePosition.Y < 7))// && (sunManagement::getInstance().getVector(2) == 1))
		{
			sunManagement::getInstance().deleteSun(2);
			buget::getBuget().addBani(25);
		}
		if ((ir.dwMousePosition.X > 80 && ir.dwMousePosition.X < 100) && (ir.dwMousePosition.Y > 0 && ir.dwMousePosition.Y < 7))// && (sunManagement::getInstance().getVector(3) == 1))
		{
			sunManagement::getInstance().deleteSun(3);
			buget::getBuget().addBani(25);
		}
		if ((ir.dwMousePosition.X > 100 && ir.dwMousePosition.X < 120) && (ir.dwMousePosition.Y > 0 && ir.dwMousePosition.Y < 7))// && (sunManagement::getInstance().getVector(4) == 1))
		{
			sunManagement::getInstance().deleteSun(4);
			buget::getBuget().addBani(25);
		}
		if ((ir.dwMousePosition.X > 120 && ir.dwMousePosition.X < 140) && (ir.dwMousePosition.Y > 0 && ir.dwMousePosition.Y < 7))// && (sunManagement::getInstance().getVector(5) == 1))
		{
			sunManagement::getInstance().deleteSun(5);
			buget::getBuget().addBani(25);
		}
		if ((ir.dwMousePosition.X > 140 && ir.dwMousePosition.X < 160) && (ir.dwMousePosition.Y > 0 && ir.dwMousePosition.Y < 7))// && (sunManagement::getInstance().getVector(6) == 1))
		{
			sunManagement::getInstance().deleteSun(6);
			buget::getBuget().addBani(25);
		}
		if ((ir.dwMousePosition.X > 160 && ir.dwMousePosition.X < 180) && (ir.dwMousePosition.Y > 0 && ir.dwMousePosition.Y < 7))// && (sunManagement::getInstance().getVector(7) == 1))
		{
			sunManagement::getInstance().deleteSun(7);
			buget::getBuget().addBani(25);
		}

		//sunflower event
		//sunflower event
		//sunflower event
		//sunflower event
		//sunflower event
		//8,0 -> 13, 19
		if ((ir.dwMousePosition.X >= 0 && ir.dwMousePosition.X < 19) && (ir.dwMousePosition.Y > 7 && ir.dwMousePosition.Y < 14))
		{
			flag_sunflower = true;
		}

		if (flag_sunflower == true)
		{
			//stanga sus 20, 21
			if ((ir.dwMousePosition.X > 20 && ir.dwMousePosition.X < 40) && (ir.dwMousePosition.Y > 21 && ir.dwMousePosition.Y < 28) && buget::getBuget().getBani() >=25)
			{
				flag_sunflower = false;
				entity *planta = new sunflower(21, 20);
				planta->drawSunflower(21, 20);
				buget::getBuget().addBani(-25);
				vectorPlante.push_back(planta);

			}
			if((ir.dwMousePosition.X > 40 && ir.dwMousePosition.X < 60) && (ir.dwMousePosition.Y > 21 && ir.dwMousePosition.Y < 28) && buget::getBuget().getBani() >= 25)
			{
				flag_sunflower = false;
				entity *planta = new sunflower(21, 40);
				planta->drawSunflower(21, 40);
				buget::getBuget().addBani(-25);
				vectorPlante.push_back(planta);
			}
			if((ir.dwMousePosition.X > 60 && ir.dwMousePosition.X < 80) && (ir.dwMousePosition.Y > 21 && ir.dwMousePosition.Y < 28) && buget::getBuget().getBani() >= 25)
			{
				flag_sunflower = false;
				entity *planta = new sunflower(21, 60);
				planta->drawSunflower(21, 60);
				buget::getBuget().addBani(-25);
				vectorPlante.push_back(planta);
			}
		}

		//peashooter event
		//peashooter event
		//peashooter event
		//peashooter event
		//peashooter event
		if ((ir.dwMousePosition.X > 0 && ir.dwMousePosition.X < 19) && (ir.dwMousePosition.Y > 14 && ir.dwMousePosition.Y < 21))
		{
			flag_peashooter = true;
		}
		//15,0 -> 20, 19 //nu e sigur	

		output += "mouse double clicked at (";
		output += std::to_string(ir.dwMousePosition.X);
		output += ", ";
		output += std::to_string(ir.dwMousePosition.Y);
		output += ")              ";
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