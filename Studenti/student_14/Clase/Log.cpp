#include "Log.h"
#include "ConsoleOutput.h"
#include "ConsoleInput.h"



Log::Log()
{
	
}

void Log::log_in()
{
	static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput &conIn = UserInterface::ConsoleInput::getInstance();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);

	std::string juc;
	std::string action;
	conOut(18, 62) << "Tastati numele dumneavoastra!";
	conOut(20, 62) << "id: \t";
	do
	{
		action = conIn.getUserActions();
		if (action.length() == 1)
		{
			juc += action;
		}

		conOut(20, 68) << juc;
	} while (action != "\r");

	this->jucator = juc;
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);


}

WORD Log::GetConsoleTextAttribute(HANDLE hCon)
{
	CONSOLE_SCREEN_BUFFER_INFO con_info;
	GetConsoleScreenBufferInfo(hCon, &con_info);
	return con_info.wAttributes;
}
