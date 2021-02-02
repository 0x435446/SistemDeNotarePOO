#include "CField.h"
#include<stdlib.h>
#define CORNER_RIGHT_DOWN 217
#define CORNER_RIGHT_UP 191
#define CORNER_LEFT_UP 218
#define CORNER_LEFT_DOWN 192
#define T_DOWN 193
#define T_UP 194
#define T_LEFT 195
#define T_RIGHT 180
#define HORIZONTAL_LINE 196
#define VERTCIAL_LINE 179
#define INTERSECTION 197

#define COL_DISTANCE 16
#define LINE_DISTANCE 6

using namespace UserInterface;

CField* CField::m_instance = (CField*)0;

CField& CField::getInstance(int level)
{
	// TODO: insert return statement here
	if (m_instance == NULL)
		m_instance = new CField(level);
	return *m_instance;
}

void UserInterface::CField::increase_score()
{
	score++;
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(3, 8) << score;
}

void CField::destroyInstance()
{
	if (m_instance == NULL)
		return;
	
	delete m_instance;
	m_instance = NULL;
}

char** CField::getField()
{
	char** teren;
	teren = (char**)malloc(37 * sizeof(char*));
	for (int i = 0; i < 37; i++)
	{
		teren[i] = (char*)malloc(160 * sizeof(char));
	}
	for (int i = 0; i < 37; i++)
	{
		for (int j = 0; j < 160; j++) 
			teren[i][j] = field[i][j];
	}
	return teren;
}

int UserInterface::CField::get_resurse()
{
	
	return resurse;
}

void UserInterface::CField::increase_resurse()
{
	resurse = resurse + 50;
}

void UserInterface::CField::decrease_resurse(int price)
{
	resurse = resurse - price;
}

void CField::add_on_field(char c,int line, int column)
{
	field[line * LINE_DISTANCE + 1][column * COL_DISTANCE + 10] = c; //1
	field[line * LINE_DISTANCE + 1][column * COL_DISTANCE + 11] = c; //2
	field[line * LINE_DISTANCE + 2][column * COL_DISTANCE + 8] = c; //3
	field[line * LINE_DISTANCE + 2][column * COL_DISTANCE + 9] = c; //4
	field[line * LINE_DISTANCE + 2][column * COL_DISTANCE + 12] = c; //5
	field[line * LINE_DISTANCE + 2][column * COL_DISTANCE + 13] = c; //6
	field[line * LINE_DISTANCE + 3][column * COL_DISTANCE + 7] = c; //7
	field[line * LINE_DISTANCE + 3][column * COL_DISTANCE + 11] = c; //8
	field[line * LINE_DISTANCE + 3][column * COL_DISTANCE + 14] = c; //9 
	field[line * LINE_DISTANCE + 4][column * COL_DISTANCE + 8] = c; //10
	field[line * LINE_DISTANCE + 4][column * COL_DISTANCE + 9] = c; //11
	field[line * LINE_DISTANCE + 4][column * COL_DISTANCE + 12] = c; //12
	field[line * LINE_DISTANCE + 4][column * COL_DISTANCE + 13] = c; //13
	field[line * LINE_DISTANCE + 5][column * COL_DISTANCE + 10] = c; //14
	field[line * LINE_DISTANCE + 5][column * COL_DISTANCE + 11] = c; //15
}

void UserInterface::CField::clear_on_field(int line,int column)
{
	field[line * LINE_DISTANCE + 1][column * COL_DISTANCE + 10] = ' '; //1
	field[line * LINE_DISTANCE + 1][column * COL_DISTANCE + 11] = ' '; //2
	field[line * LINE_DISTANCE + 2][column * COL_DISTANCE + 8] = ' '; //3
	field[line * LINE_DISTANCE + 2][column * COL_DISTANCE + 9] = ' '; //4
	field[line * LINE_DISTANCE + 2][column * COL_DISTANCE + 12] = ' '; //5
	field[line * LINE_DISTANCE + 2][column * COL_DISTANCE + 13] = ' '; //6
	field[line * LINE_DISTANCE + 3][column * COL_DISTANCE + 7] = ' '; //7
	field[line * LINE_DISTANCE + 3][column * COL_DISTANCE + 11] = ' '; //8
	field[line * LINE_DISTANCE + 3][column * COL_DISTANCE + 14] = ' '; //9 
	field[line * LINE_DISTANCE + 4][column * COL_DISTANCE + 8] = ' '; //10
	field[line * LINE_DISTANCE + 4][column * COL_DISTANCE + 9] = ' '; //11
	field[line * LINE_DISTANCE + 4][column * COL_DISTANCE + 12] = ' '; //12
	field[line * LINE_DISTANCE + 4][column * COL_DISTANCE + 13] = ' '; //13
	field[line * LINE_DISTANCE + 5][column * COL_DISTANCE + 10] = ' '; //14
	field[line * LINE_DISTANCE + 5][column * COL_DISTANCE + 11] = ' '; //15
	
}


void UserInterface::CField::add_bullet(int line, int column)
{
	field[line * LINE_DISTANCE + 3][column * COL_DISTANCE + 7] = 184;
}

void UserInterface::CField::remove_bullet(int line, int column)
{
	field[line * LINE_DISTANCE + 3][column * COL_DISTANCE + 7] = ' ';

}



void UserInterface::CField::game_over()
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for(int i=0;i<40;i++)
		for(int j=0;j<=160;j++)
		{
			if (i == 0 && j == 0) conOut(0, 0) << ' ';
			else conOut << ' ';
		}
	conOut << "\n";

	conOut(20, 75) << "GAME OVER";
	while (true);
}

char UserInterface::CField::check_field(int line,int column)
{
	for (int i = line  * LINE_DISTANCE +1; i < line * LINE_DISTANCE + LINE_DISTANCE; i++)
		for (int j = column *COL_DISTANCE +1; j < column *COL_DISTANCE + COL_DISTANCE-1; j++)
			if (field[i][j] != ' ') return field[i][j];
	return ' ';
}

CField::CField(int level)
{
	score = 0;
	resurse = 500;
		for (int i = 0; i < 37; i++)
			for (int j = 0; j < 160; j++)
		{
				if (i % 6 != 0 && j % 16 != 0) field[i][j] = ' ';
				if (i % 6 == 0)
					field[i][j] = HORIZONTAL_LINE;
				if (j % 16 == 0) field[i][j] = VERTCIAL_LINE;
				if ((i % 6 == 0) && (j % 16 == 0)) field[i][j] = INTERSECTION;
				if (j == 159) field[i][j] = VERTCIAL_LINE;
				if (i == 36) field[i][j] = HORIZONTAL_LINE;
				if ((i % 6 == 0) && (j == 0)) field[i][j] = T_LEFT;
				if ((i % 6 == 0) && (j == 159)) field[i][j] = T_RIGHT;
				if ((i == 0) && (j % 16 == 0)) field[i][j] = T_UP;
				if ((i == 36) && (j % 16 == 0)) field[i][j] = T_DOWN;
				
		}

		field[0][0] = CORNER_LEFT_UP;
		field[0][159] = CORNER_RIGHT_UP;
		field[36][159] = CORNER_RIGHT_DOWN;
		field[36][0] = CORNER_LEFT_DOWN;

		difficulty = level;
		
		add_on_field('P', 1, 0);
		add_on_field('F', 2, 0);
		add_on_field('C', 3, 0);
		add_on_field('W', 4, 0);
		add_on_field('I', 5, 0);
}

CField::~CField()
{
}
