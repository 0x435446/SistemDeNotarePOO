#pragma once
/*TODO: singleton*/
#define CON_WIDTH 1280
#define CON_HEIGHT 720
#include <iostream>


#define FIRST_ROW 5
#define FIRST_COL 5

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5

namespace UserInterface {
	class ConsoleOutput
	{
	public:
		ConsoleOutput();
		~ConsoleOutput();

		static ConsoleOutput & getInstance();
		ConsoleOutput & operator() (int row, int col);

		template <typename T>
		friend ConsoleOutput &operator<< (ConsoleOutput &out, T obj)
		{
			std::cout << obj;
			return out;
		}

		template <typename T>
		friend ConsoleOutput& operator>>(ConsoleOutput& input, T obj) {
			std::cin >> obj;
			return input;
		}

		void Create_Start();

		void Create_Plant_Zone(int row, int col);

		void Create_Score(int row, int col);

		void Create_Border1(int row, int col);

		void Create_Sun_Zone(int row, int col);

		void Create_Battle_Field(int row, int col);

		void Create_Battle_Zone(int row, int col);

		void Game_Loading();

	};
}


