#pragma once
#define W_WIDTH 1280
#define W_HEIGHT 720
#include <iostream>
class ConsoleHandler
{
	static ConsoleHandler* _instance;
	static int _instanceCount;
public:
	static ConsoleHandler& getInstance();
	static void releaseInstance();

	ConsoleHandler& operator()(int, int);
	template <typename T>
	friend ConsoleHandler& operator<<(ConsoleHandler& _out, T obj)
	{
		std::cout << obj;
		return _out;
	}

	void setColor(int color);

	void Init();
	ConsoleHandler(const ConsoleHandler&) = delete;
	ConsoleHandler(ConsoleHandler&&) = delete;
	ConsoleHandler& operator=(const ConsoleHandler&) = delete;
	ConsoleHandler& operator=(ConsoleHandler&&) = delete;

private:
	ConsoleHandler();
	~ConsoleHandler();
};