#pragma once
/*TODO: singleton*/
#define CON_WIDTH 1280
#define CON_HEIGHT 720
#include <iostream>
#include "Sun.h"
namespace UserInterface {
	class ConsoleOutput
	{
	public:
		ConsoleOutput();
		~ConsoleOutput();

		static ConsoleOutput & getInstance();
		ConsoleOutput & operator() (int col, int row);

		template <typename T>
		friend ConsoleOutput &operator<< (ConsoleOutput &out, T obj)
		{
			std::cout << obj;
			return out;
		}
		
	};
}
static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();


