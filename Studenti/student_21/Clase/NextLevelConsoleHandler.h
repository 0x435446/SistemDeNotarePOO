#pragma once
#include <Windows.h>



class ConsoleHandlerV2
{
	static int _instanceCount;
	static ConsoleHandlerV2* _instance;
	HANDLE hStdout, hNewScreenBuffer;
	SMALL_RECT srctReadRect;
	SMALL_RECT srctWriteRect;
	CHAR_INFO chiBuffer[6510];
	COORD coordBufSize;
	COORD coordBufCoord;
	BOOL fSuccess;
public:
	static ConsoleHandlerV2& getInstance();
	static void releaseInstance();

	int Init();
	ConsoleHandlerV2(const ConsoleHandlerV2&) = delete;
	ConsoleHandlerV2(ConsoleHandlerV2&&) = delete;
	ConsoleHandlerV2& operator=(const ConsoleHandlerV2&) = delete;
	ConsoleHandlerV2& operator=(ConsoleHandlerV2&&) = delete;

	void updateConsoleBuffer(char pixel, int color, int x, int y);
	void Draw();
	void reset();

private:
	ConsoleHandlerV2();
	~ConsoleHandlerV2();
};

