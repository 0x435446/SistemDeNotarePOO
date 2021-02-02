#include "engine.h"


engine::engine()
{
	screenWidth = 80;
	screenHeight = 30;
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	consoleIn = GetStdHandle(STD_INPUT_HANDLE);
	appName = L"Default";
}


engine::~engine()
{
	SetConsoleActiveScreenBuffer(originalConsole);
	delete[] bufScreen;
}

void engine::start()
{
	isAtomActive = true;
	std::thread t = std::thread(&engine::GameThread, this);

	t.join();
}

int engine::getScreenWidth()
{
	return this->screenWidth;
}

int engine::getScreenHeight()
{
	return this->screenHeight;
}

int engine::constructConsole(int width, int height, int fontw, int fonth)
{
	try{
		if (console == INVALID_HANDLE_VALUE)
			throw std::exception("invalid handle value");
		screenWidth = width;
		screenHeight = height;
		//schimb marimea vizuala a consolei la un minim ca ScreenBuffer ul sa se micsoreze
		rectWindow = { 0, 0, 1, 1 };
		SetConsoleWindowInfo(console, true, &rectWindow);

		//setez marimea screen buferr ului
		COORD coord = { (short)screenWidth, (short)screenHeight };
		if (!SetConsoleScreenBufferSize(console, coord))
			throw std::exception("SetConsoleBufferSize error");

		//asignez screen bufferul consolei 
		if (!SetConsoleActiveScreenBuffer(console))
			throw std::exception("SetConsoleActiveScreenBuffer error");

		//setez marimea fontului
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 0;
		cfi.dwFontSize.X = fontw;
		cfi.dwFontSize.Y = fonth;
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;

		wcscpy_s(cfi.FaceName, L"Console");
		if (!SetCurrentConsoleFontEx(console, false, &cfi))
			throw std::exception("SetCurrentConsoleFontEx");

		//verific daca este depasita marimea maxima a consolei
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		if (!GetConsoleScreenBufferInfo(console, &csbi))
			throw(std::exception("GetConsoleScreenBufferInfo"));
		if (screenHeight > csbi.dwMaximumWindowSize.Y)
			throw(std::exception("Screen Height / Font Height Too Big"));
		if (screenWidth > csbi.dwMaximumWindowSize.X)
			throw(std::exception("Screen Width / Font Width too big"));

		//setez marimea fizica a consolei
		rectWindow = { 0, 0, (short)screenWidth - 1, (short)screenHeight - 1 };
		if (!SetConsoleWindowInfo(console, true, &rectWindow))
			throw(std::exception("SetConsoleWindowInfo"));

		//flag uri pt inputul de la mouse
		if (!SetConsoleMode(consoleIn, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS))
			throw(std::exception("SetConsoleMode"));

		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO     cursorInfo;
		GetConsoleCursorInfo(handle, &cursorInfo);
		cursorInfo.bVisible = false; // set the cursor visibility
		SetConsoleCursorInfo(handle, &cursorInfo);

		//aloc memorie pt screen buffer
		bufScreen = new CHAR_INFO[screenWidth * screenHeight];
		memset(bufScreen, 0, sizeof(CHAR_INFO) * screenWidth * screenHeight);

		SetConsoleCtrlHandler((PHANDLER_ROUTINE)CloseHandler, TRUE);
	}catch(std::exception e) {
		std::cout << "dude" << std::endl << GetLastError();
		std::cout << e.what();
	}
	return 1;
	
}

bool engine::isFocused()
{ 
	return true;
	
}

void engine::draw(int x, int y, short c , short col ) {
	if (x >= 0 && x < screenWidth && y >= 0 && y < screenHeight) {
		bufScreen[y * screenWidth + x].Char.UnicodeChar = c;
		bufScreen[y * screenWidth + x].Attributes = col;
	}
}



void engine::drawEntity(int x, int y, Entity* enti) {
	int xe = x + 10;
	int ye = y + 10;
	if (enti == nullptr) throw std::exception("something is wrong");
	clip(x, y);
	clip(xe, ye);
	for (int i = x; i < xe; i++)
		for (int j = y; j < ye; j++)
			draw(i, j, enti->sprite.pixels[j - y + 1][i - x + 1].glyph, enti->sprite.pixels[j - y + 1][i - x + 1].colour);
}

void engine::fill(int x1, int y1, int x2, int y2, short c, short col)
{
	clip(x1, y1);
	clip(x2, y2);
	for (int x = x1; x < x2; x++)
		for (int y = y1; y < y2; y++)
			draw(x, y, c, col);
}

void engine::clip(int & x, int & y)
{
	if (x < 0) x = 0;
	if (x > screenWidth) x = screenWidth;
	if (y < 0) y = 0;
	if (y > screenHeight) y = screenHeight;
}

void engine::DrawString(int x, int y, std::string c, short col)
{
	for (size_t i = 0; i < c.size(); i++)
	{
		bufScreen[y * screenWidth + x + i].Char.UnicodeChar = c[i];
		bufScreen[y * screenWidth + x + i].Attributes = col;
	}
}

void engine::mouseEventProc(MOUSE_EVENT_RECORD ir)
{
	std::string output = "Mouse event: ";
	switch (ir.dwEventFlags)
	{
	case MOUSE_MOVED:
		mousePosX = ir.dwMousePosition.X;
		mousePosY = ir.dwMousePosition.Y;
		break;
	case DOUBLE_CLICK:
		mousePosX = ir.dwMousePosition.X;
		mousePosY = ir.dwMousePosition.Y;
		hasDoubledClicked = true;
		break;
	}
}


void engine::GameThread()
{
	if (!onUserCreate())
		isAtomActive = false;

	auto time1 = std::chrono::system_clock::now();
	auto time2 = std::chrono::system_clock::now();

	while (isAtomActive) {

		//functioneaza cat mai rapid
		while (isAtomActive) {
			time2 = std::chrono::system_clock::now();
			std::chrono::duration<float> specialTime = time2 - time1;
			time1 = time2;
			float f_specialTime = specialTime.count(); // timpul dintre frame ul curent si cel anterior

			//Prerucrarea inputului de la tastatura
			//TO_DO

			//Prelucrarea inputului de la mouse - windows events
			try { //will break without try-catch block xD
				DWORD nr = 0;
				INPUT_RECORD inBuf[32];
				DWORD events = 0;
				GetNumberOfConsoleInputEvents(consoleIn, &events);
				if (events > 0)
				{
					if (!ReadConsoleInput(consoleIn, inBuf, events, &events))
						throw std::exception("ReadConsoleInput");

					// Dispatch the events to the appropriate handler. 
					for (int i = 0; i < events; i++)
					{
						switch (inBuf[i].EventType)
						{

							//case KEY_EVENT: // keyboard input 
							//	return keyEventProc(irInBuf[i].Event.KeyEvent);

						case MOUSE_EVENT: // mouse input 
							mouseEventProc(inBuf[i].Event.MouseEvent);
							break;

							//case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
							//	return resizeEventProc(irInBuf[i].Event.WindowBufferSizeEvent);

						//case FOCUS_EVENT:  // disregard focus events 
						//	isConsoleFocused = inBuf[i].Event.FocusEvent.bSetFocus;
						//	break;

						default:
							throw std::exception("unknown event type");
							break;
						}
					}
				}
			}
			catch (std::exception e) {
				std::cout << e.what();
			}



			//frame update
			if (!onUserUpdate(f_specialTime))
				isAtomActive = false;
			hasDoubledClicked = false;
			/*
				wchar_t s[256];
				swprintf_s(s, 256, L"OneLoneCoder.com - Console Game Engine - %s - FPS: %3.2f", m_sAppName.c_str(), 1.0f / fElapsedTime);
				SetConsoleTitle(s);
			*/
			WriteConsoleOutput(console, bufScreen, { (short)screenWidth, (short)screenHeight }, { 0,0 }, &rectWindow);

		}
	}
}

BOOL engine::CloseHandler(DWORD evt)
{
	//functie care reprezinta evenimentul de inchidere a jocului, inchide thread ul jocului, 
	if (evt == CTRL_CLOSE_EVENT)
	{
		isAtomActive = false;

		// astept ca thread ul sa fie oprit
		std::unique_lock<std::mutex> ul(muxGame);
		gameFinished.wait(ul);
	}
	return true;
}

std::atomic<bool> engine::isAtomActive(false);
std::condition_variable engine::gameFinished;
std::mutex engine::muxGame;
