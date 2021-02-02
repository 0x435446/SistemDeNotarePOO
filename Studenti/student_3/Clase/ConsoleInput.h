#pragma once
#include <windows.h>
#include "ConsoleInput.h"
#include <string>
#include <vector>
#include "plants.h"
#include "zombie.h"
/*TODO: singleton*/
namespace UserInterface
{
	class ConsoleInput
	{
	private:
		HANDLE hStdin;
		DWORD cNumRead, fdwMode, fdwSaveOldMode, i;
		INPUT_RECORD irInBuf[128];
		std::string mouseEventProc(MOUSE_EVENT_RECORD);
		std::string resizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
		std::string keyEventProc(KEY_EVENT_RECORD);

	public:
		static bool flag_sunflower;
		static bool flag_peashooter;
		ConsoleInput();
		~ConsoleInput();
		std::vector<entity*> vectorPlante;
		static ConsoleInput & getInstance(void);
		std::string getUserActions();
	};
}


