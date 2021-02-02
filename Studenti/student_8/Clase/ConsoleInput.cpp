#include <stdio.h>
#include <windows.h>
#include "ConsoleInput.h"
#include <string>
#include <iostream>//da nu cred ca afiseazain consola lor
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
	std::string output ;
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
		//output += "mouse double clicked at (";
		//asta da outputul de la mouse 
		output += std::to_string(ir.dwMousePosition.X);
		output += " ";
		output += std::to_string(ir.dwMousePosition.Y);
		//output += ")              ";
		return output;
	}
	return output;
}
std::string ConsoleInput::resizeEventProc(WINDOW_BUFFER_SIZE_RECORD) { return ""; };
std::string ConsoleInput::keyEventProc(KEY_EVENT_RECORD ir) //asta da ceva daca apesi o cheie ,crek merge ca pla ca is la clinceni si e semnal prost aci 
{
	std::string output;
	
	switch (ir.wVirtualKeyCode)//pentru ca nu e BKeyDown, dada
	{
	case 49:
	{output = "1"; break; }
	case 50:
	{output = "2"; break; }
	default:
		output = "9";//l-am pus 9 ca cu E crapa ca incerca sa faca stoi(
	}//am apasat 1 ,poate nu asa e case ,prost
	//ba da acu daca apasa pe altceva se intampla ceva ?si aici e iar futai ca trebuie fututa toata consola ca am zis ca merge cu cin ,sa-mi bag pla eu 
	//nu cred doar ca se intoarce un output aiurea
	//pare ca si pentru 1 si pentru 2 tot E da, cplm
	//ai putea sa dai pe default o valoare pe care sa stii sa o tratezi in main
	std::cout << output; //cu ce il printez pe asta ba? ce e ? unicode ? std string
	return output;
};

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