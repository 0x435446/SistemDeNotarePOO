#pragma once
#include<stdio.h>
#include "ConsoleInput.h"
#include"ConsoleOutput.h"


namespace UserInterface {
	class CField
	{
	public:
		static CField& getInstance(int level);
		void increase_score();
		static void destroyInstance();
		char** getField();
		int get_resurse();
		void increase_resurse();
		void decrease_resurse(int price);
		void add_on_field(char c, int line, int column);
		void clear_on_field(int line, int column);
		void add_bullet(int line, int column);
		void remove_bullet(int line, int column);
		void game_over();

		char check_field(int line, int column);
		~CField();
		char field[37][160];
	private:
		static CField* m_instance;
		unsigned int resurse;
		unsigned int difficulty;
		CField(int level);
		unsigned int score;
	};
}
