#pragma once
#include <Windows.h>
#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <thread>
#include <atomic>
#include <condition_variable>
#include <exception>
#include <stdio.h>
#include "Entity.h"

class engine
{
public:
	engine();
	~engine();
	void start();
	int getScreenWidth();
	int getScreenHeight();
	int constructConsole(int width, int height, int fontw, int fonth);
private:
	void GameThread();
	static BOOL CloseHandler(DWORD evt);
	void mouseEventProc(MOUSE_EVENT_RECORD ir);
protected:
	bool isFocused();
	virtual void draw(int x, int y, short c = 0x2588, short col = 0x000F);
	void drawEntity(int x, int y, Entity* enti);
	void fill(int x1, int y1, int x2, int y2, short c = 0x2588, short col = 0x000F);
	void clip(int &x, int &y);
	virtual bool onUserCreate() = 0; //functie apelata la lansarea thread ului, daca returneaza false jocul se opreste
	virtual bool onUserUpdate(float f_specialTime) = 0;//functie apelata pt fiecare frame
	void DrawString(int x, int y, std::string c, short col = 0x000F);
	
	int screenWidth;
	int screenHeight;
	CHAR_INFO *bufScreen;
	std::wstring appName;
	HANDLE originalConsole;
	CONSOLE_SCREEN_BUFFER_INFO originalConsoleInfo;
	HANDLE console;
	HANDLE consoleIn;
	SMALL_RECT rectWindow;
	bool isConsoleFocused = true;
	static std::atomic<bool> isAtomActive;
	static std::condition_variable gameFinished;
	static std::mutex muxGame;
	bool hasDoubledClicked = false;
	int mousePosX;
	int mousePosY;
};


