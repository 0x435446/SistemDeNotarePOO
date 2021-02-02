#pragma once
#include <windows.h>
#include <string>
class MouseHandler
{
	static MouseHandler* _instance;
	static int _instanceCount;

	HANDLE hStdin;
	DWORD cNumRead, fdwMode, fdwSaveOldMode, i;
	INPUT_RECORD irInBuf[128];

	int mousePosX;
	int mousePosY;
	int processedInput;
public:
	static MouseHandler& getInstance();
	static void releaseInstance();
	int getPosX() { return mousePosX; }
	int getPosY() { return mousePosY; }
	
	MouseHandler(const MouseHandler&) = delete;
	MouseHandler(MouseHandler&&) = delete;
	MouseHandler& operator=(const MouseHandler&) = delete;
	MouseHandler& operator=(MouseHandler&&) = delete;

	void processInput();
	int getProcessedInput();

private:
	MouseHandler();
	~MouseHandler();
	void Init();
};