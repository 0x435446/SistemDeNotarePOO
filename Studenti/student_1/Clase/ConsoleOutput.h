#pragma once
#include <iostream>
#include <Windows.h>

namespace UserInterface
{
	class ConsoleOutput
	{
	private:
		static ConsoleOutput* console;

		ConsoleOutput();
		ConsoleOutput(ConsoleOutput&);
		~ConsoleOutput();

		int width;
		int height;

	public:
		static ConsoleOutput& getInstance();
		static void destroyInstance();

		ConsoleOutput& operator() (int row, int col);
		ConsoleOutput& operator[] (int);

		template <typename T>
		friend ConsoleOutput &operator<< (ConsoleOutput &out, T obj)
		{
			std::cout << obj;
			return out;
		}
	};
}

