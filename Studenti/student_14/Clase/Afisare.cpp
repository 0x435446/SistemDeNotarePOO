#define _CRT_SECURE_NO_WARNINGS
#include "Afisare.h"
#include "Action.h"

#include <conio.h>

#define SUN_BOARD_Y_START 10
#define SUN_BOARD_X_START 21
#define BOARD_SCORE_X_START 10
#define BOARD_PLANTS_X 10
#define BOARD_PLANTS_Y 15
#define MULTY 12
#define BOARD_PLAYGROUND_Y_START 16
#define BOARD_PLAYGROUND_Y_END 19
#define BOARD_PLAYGROUND_X_START 22
#define BOARD_PLAYGROUND_X_END  32
#define PLANTS_PRICE_X 5
#define PLANTS_PRICE_Y 18
#define COST_PEA 80
#define COST_SUNFLOWER 100
#define COST_WALLNUT 50
#define COST_CHERRY 30
#define COST_FROZENPEA 120

Afisare::Afisare()
{

}

Afisare::~Afisare()
{
}

Afisare * Afisare::instance = nullptr;
Afisare & Afisare::getInstance(void)
{
	if (Afisare::instance==nullptr)
	{
		instance = new Afisare();
	}

	return *instance;
}

using namespace std::chrono;

void Afisare::doLoadingBar()
{
	static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "*";

	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > 150)
	{
		begin = end;
		conOut(ROW_TITLE + 3, col) << printedChar;
		if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS) {
			if (printedChar == "*")
			{
				printedChar = " ";
			}
			else
			{
				printedChar = "*";
			}
			col = COL_FIRST_STAR_POSITION;
		}
		else
		{
			col += COL_DISTANCE_BETWEEN_STARS;
		}
	}
}

void Afisare::printTitle()
{
	static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput &conIn = UserInterface::ConsoleInput::getInstance();

	system("color 02");
	conOut(ROW_TITLE - 10, COL_FIRST_STAR_POSITION - 3) << "******************************";
	for (int i = 1; i < 43; i++)
	{
		for (int j = 1; j < 43; j++)
		{
			if (((i == 1) & (j == 1 || j == 7 || j == 9 || j == 17 || j == 25 || j == 29 || j == 31 || j == 33 || j == 35 || j == 41))    //prima linie din PvZ  
				|| ((i == 3) & (j == 1 || j == 7 || j == 11 || j == 19 || j == 23 || j == 33 || j == 41))								  // a doua etc...
				|| ((i == 5) & (j == 1 || j == 7 || j == 9 || j == 19 || j == 23 || j == 31 || j == 41))
				|| ((i == 7) & (j == 1 || j == 7 || j == 21 || j == 29 || j == 31 || j == 33 || j == 35 || j == 41)))
			{
				conOut(ROW_TITLE - 9 + i, COL_FIRST_STAR_POSITION - 10 + j) << "*";
				conOut(ROW_TITLE - 9 + i, COL_FIRST_STAR_POSITION - 10 + j + 1) << "*";       // pe toate le dublez sa fie scrisul mai gros 

				conOut(ROW_TITLE - 8 + i, COL_FIRST_STAR_POSITION - 10 + j) << "*";
				conOut(ROW_TITLE - 8 + i, COL_FIRST_STAR_POSITION - 10 + j + 1) << "*";
			}

		}
	}
	conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION - 3) << "******************************";
	double TimeToRunInSecs = 1;
	clock_t c = clock();
	while (double(clock() - c) / CLOCKS_PER_SEC < TimeToRunInSecs)
	{
		doLoadingBar();
		std::string action = conIn.getUserActions();

	}
	system("cls");
}

int Afisare::check_board(int x_end, int y_end, int level, int tip_planta)
{
	Action &checker = Action::getInstance();
	static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

	int ok;//contor  care verifica daca coordonatele primite sunt in interiorul tablei de joc pt nivelul corect
	std::string name;
	std::string aux;
	int i, j;

	if ((y_end >= BOARD_PLAYGROUND_Y_START) && (y_end <= BOARD_PLAYGROUND_Y_END))
	{
		j = 0;
	}
	else if ((y_end >= BOARD_PLAYGROUND_Y_START + 5 * 1) && (y_end <= BOARD_PLAYGROUND_Y_END + 5 * 1))
	{
		j = 1;
	}
	else if ((y_end >= BOARD_PLAYGROUND_Y_START + 5 * 2) && (y_end <= BOARD_PLAYGROUND_Y_END + 5 * 2))
	{
		j = 2;
	}
	else if ((y_end >= BOARD_PLAYGROUND_Y_START + 5 * 3) && (y_end <= BOARD_PLAYGROUND_Y_END + 5 * 3))
	{
		j = 3;
	}
	else if ((y_end >= BOARD_PLAYGROUND_Y_START + 5 * 4) && (y_end <= BOARD_PLAYGROUND_Y_END + 5 * 4))
	{
		j = 4;
	}
	else
	{
		return 1;
	}

	//pentru level 1
	if ((j==2)&&(level==1))
	{
		ok=1;
	}
	else if (((j==2)||(j==1)||(j==3))&&(level==2))
	{
		ok = 1;
	}
	else
	{
		return 1;
	}

	if ((x_end >= BOARD_PLAYGROUND_X_START) && (x_end <= BOARD_PLAYGROUND_X_END))
	{
		i = 0;
	}
	else if ((x_end >= BOARD_PLAYGROUND_X_START + MULTY * 1) && (x_end <= BOARD_PLAYGROUND_X_END + MULTY * 1))
	{
		i = 1;
	}
	else if ((x_end >= BOARD_PLAYGROUND_X_START + MULTY * 2) && (x_end <= BOARD_PLAYGROUND_X_END + MULTY * 2))
	{
		i = 2;
	}
	else if ((x_end >= BOARD_PLAYGROUND_X_START + MULTY * 3) && (x_end <= BOARD_PLAYGROUND_X_END + MULTY * 3))
	{
		i = 3;
	}
	else if ((x_end >= BOARD_PLAYGROUND_X_START + MULTY * 4) && (x_end <= BOARD_PLAYGROUND_X_END + MULTY * 4))
	{
		i = 4;
	}
	else if ((x_end >= BOARD_PLAYGROUND_X_START + MULTY * 5) && (x_end <= BOARD_PLAYGROUND_X_END + MULTY * 5))
	{
		i = 5;
	}
	else if ((x_end >= BOARD_PLAYGROUND_X_START + MULTY * 6) && (x_end <= BOARD_PLAYGROUND_X_END + MULTY * 6))
	{
		i = 6;
	}
	else if ((x_end >= BOARD_PLAYGROUND_X_START + MULTY * 7) && (x_end <= BOARD_PLAYGROUND_X_END + MULTY * 7))
	{
		i = 7;
	}
	else if ((x_end >= BOARD_PLAYGROUND_X_START + MULTY * 8) && (x_end <= BOARD_PLAYGROUND_X_END + MULTY * 8))
	{
		i = 8;
	}
	else
	{
		return 1;

	}

	name=checker.matrix[i][j]->get_name();
	if ((name=="default")&&(tip_planta==1))
	{
		delete checker.matrix[i][j];
		checker.matrix[i][j] = new Pea;
		checker.matrix[i][j]->set_j(j,i);
		print_pea(i, j);

		
		return 0;
	}
	else if ((name == "default") && (tip_planta == 2))
	{
		delete checker.matrix[i][j];
		checker.matrix[i][j] = new Sunflower;
		checker.matrix[i][j]->set_j(j,i);
		print_sunflower(i, j);
		return 0;
	}
	else if ((name == "default") && (tip_planta == 3))
	{
		delete checker.matrix[i][j];
		checker.matrix[i][j] = new Cherry;
		checker.matrix[i][j]->set_j(j,i);
		print_cherrybomb(i, j);
		return 0;
	}
	else if ((name == "default") && (tip_planta == 4))
	{
		delete checker.matrix[i][j];
		checker.matrix[i][j] = new Wallnut;
		checker.matrix[i][j]->set_j(j,i);
		print_wallnut(i, j);
		return 0;
	}
	else if ((name == "default") && (tip_planta == 5))
	{
		delete checker.matrix[i][j];
		checker.matrix[i][j] = new Snowpea;
		checker.matrix[i][j]->set_j(j,i);
		print_snowpea(i, j);
		return 0;
	}
	else
	{
		return 1;
	}

}

void Afisare::Board_sun()
{
	static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();


	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int saved_colors = GetConsoleTextAttribute(hConsole);

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
	//SetConsoleTextAttribute(hConsole, saved_colors);
	
	//printez score counter

	conOut(9, 12) <<    "_____";
	conOut(10, 11)  << "/";
	conOut(10, 17) << "\\";
	conOut(11, 10) << "/--";
	conOut(11,16)<< "--\\";
	conOut(12, 10) << "\\";
	conOut(12, 18) << "/";
	conOut(12, 11)  << "_______";
	

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);

	//afisez tabelele pt sori

	for (int y = SUN_BOARD_Y_START -2; y < (5*2)+ SUN_BOARD_Y_START -2; y=y+5)
	{
		for (int x = SUN_BOARD_X_START ; x <= 81 + SUN_BOARD_X_START; x ++)
		{
			if (!    (   (y==13)&&((x== SUN_BOARD_X_START)||(x== SUN_BOARD_X_START + 9 *1) || (x == SUN_BOARD_X_START + 9 *2) || (x == SUN_BOARD_X_START + 9 *3) || (x == SUN_BOARD_X_START + 9 *4) || (x == SUN_BOARD_X_START + 9 *5) || (x == SUN_BOARD_X_START + 9 *6) || (x == SUN_BOARD_X_START + 9 *7) || (x == SUN_BOARD_X_START + 9 *8) || (x == SUN_BOARD_X_START + 9 *9))))
			conOut(y, x) << "_";
		}
	}
	
	for (int y = SUN_BOARD_Y_START -1  ; y < SUN_BOARD_Y_START + 5 -1 ; y++)
	{
		for (int x = SUN_BOARD_X_START ; x <= 81 +SUN_BOARD_X_START; x += 9)
		{
			
				conOut(y, x) << "|";
		}

	}

}

void Afisare::Board_plants()
{
	static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN  );
	for (int i = 0; i < 5*5; i+=5)
	{
		conOut(BOARD_PLANTS_Y + i, 13) << "___";
		conOut(BOARD_PLANTS_Y + 1 + i, 12) << "/";
		conOut(BOARD_PLANTS_Y + 1 + i, 16) << "\\";
		conOut(BOARD_PLANTS_Y + 2 + i, 11) << "/";
		conOut(BOARD_PLANTS_Y + 2 + i, 17) << "\\";
		conOut(BOARD_PLANTS_Y + 3 + i, 10) << "|";
		conOut(BOARD_PLANTS_Y + 3 + i, 18) << "|";
		conOut(BOARD_PLANTS_Y + 4 + i, 11) << "\\";
		conOut(BOARD_PLANTS_Y + 4 + i, 17) << "/";
		conOut(BOARD_PLANTS_Y + 5 + i, 12) << "\\";
		conOut(BOARD_PLANTS_Y + 5 + i, 16) << "/";
		if (i==5*4)
		{
			conOut(BOARD_PLANTS_Y + 5 + i, 13) << "___";
		}

	}
	//pentru planta Pea;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN| FOREGROUND_RED | FOREGROUND_BLUE);
	conOut(BOARD_PLANTS_Y + 2, 13) << "O.O ";
	conOut(BOARD_PLANTS_Y + 3, 14) << "O";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN );
	conOut(BOARD_PLANTS_Y + 4, 14) << "|";

	//pentru planta sunflower
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN| FOREGROUND_RED);
	conOut(BOARD_PLANTS_Y + 2 + 5, 12) << "/\\ /\\";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	conOut(BOARD_PLANTS_Y + 3 + 5, 12) << "_-O-_";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
	conOut(BOARD_PLANTS_Y + 4 + 5, 12) << "\\/ \\/";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	conOut(BOARD_PLANTS_Y + 4 + 5, 14) << "|";


	//pentru planta Cherry bomb
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	conOut(BOARD_PLANTS_Y + 10 + 2, 13) << "\\o/";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE);
	conOut(BOARD_PLANTS_Y + 10 + 3, 13) << "_I_";

	//pentru planta WAll-nut sau Cartoful :))
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	conOut(BOARD_PLANTS_Y + 15 + 1, 14) << "_";
	conOut(BOARD_PLANTS_Y + 15 + 2, 13) << "/ \\";
	conOut(BOARD_PLANTS_Y + 15 + 3, 12) << "/^ ^\\";
	conOut(BOARD_PLANTS_Y + 15 + 4, 12) << "\\_-_/";

	//pentru planta frozen pea sau "jmecheru' da gheata"
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	conOut(BOARD_PLANTS_Y + 20 + 2, 14) << "__";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	conOut(BOARD_PLANTS_Y + 20 + 3, 13) << "|";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	conOut(BOARD_PLANTS_Y + 20 + 3, 14) << "o";
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
	conOut(BOARD_PLANTS_Y + 20 + 3, 15) << "~**";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN );
	conOut(BOARD_PLANTS_Y + 20 + 4, 14) << "|";


	//pentru preturi:
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	conOut(PLANTS_PRICE_Y - 1, PLANTS_PRICE_X + 1) << "/  \\";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	//conOut(PLANTS_PRICE_Y, PLANTS_PRICE_X + 2) << "PEA ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN |  FOREGROUND_RED);
	conOut(PLANTS_PRICE_Y , PLANTS_PRICE_X+2) << COST_PEA;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	conOut(PLANTS_PRICE_Y + 1, PLANTS_PRICE_X + 1) << "\\  /";
	//pentru sunflower
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	conOut(PLANTS_PRICE_Y - 1 + 5 * 1, PLANTS_PRICE_X + 1) << "/  \\";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	//conOut(PLANTS_PRICE_Y + 5 * 1, PLANTS_PRICE_X - 3) << "SUNFLOWER ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
	conOut(PLANTS_PRICE_Y + 5 * 1, PLANTS_PRICE_X + 1 ) << COST_SUNFLOWER;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	conOut(PLANTS_PRICE_Y + 1 + 5 * 1, PLANTS_PRICE_X + 1) << "\\  /";
	//pentru cherry
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	conOut(PLANTS_PRICE_Y - 1 + 5 * 2, PLANTS_PRICE_X + 1) << "/  \\";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	//conOut(PLANTS_PRICE_Y + 5 * 2, PLANTS_PRICE_X - 1) << "CHERRY ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
	conOut(PLANTS_PRICE_Y + 5 * 2, PLANTS_PRICE_X + 2) << COST_CHERRY;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	conOut(PLANTS_PRICE_Y + 1 + 5 * 2, PLANTS_PRICE_X + 1) << "\\  /";
	//pentru wallnut
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	conOut(PLANTS_PRICE_Y - 1 + 5 * 3, PLANTS_PRICE_X + 1) << "/  \\";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	//conOut(PLANTS_PRICE_Y + 5 * 3, PLANTS_PRICE_X - 2) << "WALLNUT ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
	conOut(PLANTS_PRICE_Y + 5 * 3, PLANTS_PRICE_X + 2) << COST_WALLNUT;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	conOut(PLANTS_PRICE_Y + 1 + 5 * 3, PLANTS_PRICE_X + 1) << "\\  /";
	//pentru frozen
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	conOut(PLANTS_PRICE_Y - 1 + 5 * 4, PLANTS_PRICE_X + 1) << "/  \\";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	//conOut(PLANTS_PRICE_Y + 5 * 4, PLANTS_PRICE_X - 4) << "FROZEN-PEA ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
	conOut(PLANTS_PRICE_Y + 5 * 4, PLANTS_PRICE_X + 1) << COST_FROZENPEA;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	conOut(PLANTS_PRICE_Y + 1 + 5 * 4, PLANTS_PRICE_X + 1) << "\\  /";
}

void Afisare::Board_level_one()
{
	static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN| FOREGROUND_BLUE | FOREGROUND_RED);
		for (int x=0; x <= MULTY*9; x++)
		{
			conOut(BOARD_PLANTS_Y + 10 , SUN_BOARD_X_START + x ) << "_";
	
			if (! ((x==0)||(x== MULTY *1) || (x == MULTY *2) || (x == MULTY *3) || (x == MULTY *4) || (x == MULTY *5) || (x == MULTY *6) || (x == MULTY *7) || (x == MULTY *8) || (x == MULTY *9 )))
			{
				conOut(BOARD_PLANTS_Y + 10 + 5, SUN_BOARD_X_START  + x) << "_";
			}
			
		}
	
	for (int x = 0; x <= MULTY * 9; x += MULTY)
	{
		for (int y = 0; y <5;y++ )
		{
			conOut(BOARD_PLANTS_Y + 11 +y, SUN_BOARD_X_START + x) << "|";
		}
	}
}

void Afisare::print_lose()
{
	static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	system("color 0C");
	conOut(4, 55) << "You Failed";
	_getch();
}

WORD Afisare::GetConsoleTextAttribute(HANDLE hCon)
{
	CONSOLE_SCREEN_BUFFER_INFO con_info;
	GetConsoleScreenBufferInfo(hCon, &con_info);
	return con_info.wAttributes;
}
