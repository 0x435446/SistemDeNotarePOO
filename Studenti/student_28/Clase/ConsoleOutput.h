#pragma once
/*TODO: singleton*/
#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<chrono>
#include<iostream>
#include<string>
#include<vector>
#include <time.h>
#include<conio.h>
#include<stdlib.h>

#define CON_WIDTH 1280
#define CON_HEIGHT 720


namespace UserInterface {
	class ConsoleOutput
	{
		static ConsoleOutput* instance;
		ConsoleOutput();
		~ConsoleOutput();
	public:
		static ConsoleOutput & getInstance();
		ConsoleOutput & operator() (int row, int col);

		template <typename T>
		friend ConsoleOutput &operator<< (ConsoleOutput &out, T obj)
		{
			std::cout << obj;
			return out;
		}
	};
}


