#pragma once
#include <iostream>

#define CON_WIDTH 1280
#define CON_HEIGHT 720

/*TODO: singleton*/

namespace UserInterface
{
	class ConsoleOutput
	{
	public:
		ConsoleOutput();
		~ConsoleOutput();

		static ConsoleOutput& GetInstance();
		ConsoleOutput& operator() (int row, int col);

		template <typename T>
		friend ConsoleOutput& operator<< (ConsoleOutput& out, T obj)
		{
			std::cout << obj;
			return out;
		}
	};
}