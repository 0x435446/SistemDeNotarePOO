#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include"CResursa.h"
#include "CField.h"
#include"IPlant.h"
#include"P_Z.h"
#include"IZombie.h"
#include <time.h>
#include <chrono>
#include<string>
#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5


using namespace UserInterface;
using namespace std::chrono;
using namespace std;

void doLoadingBar()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "*";

	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > 150)
	{
		begin = end;
		conOut(ROW_TITLE + 1, col) << printedChar;
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


void doLoadField(int level, UserInterface::CField& game, P_Z& maingame, int sun_rate)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	char** teren = game.getField();

	CResursa add_resurse;

	static auto begin_res = steady_clock::now();
	auto end_res = steady_clock::now();
	if (duration_cast<milliseconds>(end_res - begin_res).count() > 7000 - sun_rate * 1000)
	{
		add_resurse.newSun(game);
		begin_res = end_res;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 17; j < 160; j++)
			{
				if (j == 17) conOut(i, 17) << teren[i][j];
				else conOut << teren[i][j];
			}
			
		}
	}

	static auto begin = steady_clock::now();
	auto end = steady_clock::now();


	static auto begin_zombie = steady_clock::now();
	auto end_zombie = steady_clock::now();
	if (duration_cast<milliseconds>(end_zombie - begin_zombie).count() > 2200)
	{
		begin_zombie = end_zombie;
		maingame.move_zombies(game);
		if (level == 1)
		{
			for (int i = 18; i < 24; i++)
				for (int j = 16; j < 160; j++)
				{
					if (j == 16) conOut(i, j) << teren[i][j];
					else conOut << teren[i][j];
				}
		}
		else if (level == 2)
		{
			for (int i = 12; i < 30; i++)
				for (int j = 16; j < 160; j++)
				{
					if (j == 16) conOut(i, j) << teren[i][j];
					else conOut << teren[i][j];
				}
		}
		else if (level == 3)
		{
			for (int i = 6; i < 36; i++)
				for (int j = 16; j < 160; j++)
				{
					if (j == 16) conOut(i, j) << teren[i][j];
					else conOut << teren[i][j];
				}
		}
	}

	static auto begin_new_zombie = steady_clock::now();
	auto end_new_zombie = steady_clock::now();
	if (duration_cast<milliseconds>(end_new_zombie - begin_new_zombie).count() > 3000)
	{
		begin_new_zombie = end_new_zombie;
		if ((level == 1 && game.check_field(3, 9) == ' ') ||
			(level == 2 &&( game.check_field(3, 9) == ' ' || game.check_field(2, 9) == ' '|| game.check_field(4, 9) == ' '))||
			(level==3) && (game.check_field(3, 9) == ' ' || game.check_field(2, 9) == ' ' || game.check_field(4, 9) == ' ')|| game.check_field(1, 9) == ' '|| game.check_field(5, 9) == ' ')
		if (rand() % 2 == 1)
			maingame.add_zombie(*maingame.create_normal_zombie(level, game));
		else maingame.add_zombie(*maingame.create_buckethead_zombie(level, game));

	}

	static auto begin_bullet = steady_clock::now();
	auto end_bullet = steady_clock::now();
	if (duration_cast<milliseconds>(end_bullet - begin_bullet).count() > 1500)
	{
		begin_bullet = end_bullet;
		maingame.shoot(game);
		
	}


	if (duration_cast<milliseconds>(end - begin).count() > 300)
	{

		maingame.move_bullets(game);

		begin = end;
		

		if (level == 1)
		{
			for(int i=18;i<24;i++)
				for (int j = 16; j < 160; j++)
				{
					if (j == 16) conOut(i, j) << teren[i][j];
					else conOut << teren[i][j];
				}
		}
		else if (level == 2)
		{
			for (int i = 12; i < 30; i++)
				for (int j = 16; j < 160; j++)
				{
					if (j == 16) conOut(i, j) << teren[i][j];
					else conOut << teren[i][j];
				}
		}
		else if (level == 3)
		{
			for (int i = 6; i < 36; i++)
				for (int j = 16; j < 160; j++)
				{
					if (j == 16) conOut(i, j) << teren[i][j];
					else conOut << teren[i][j];
				}
		}

		
	}


}

void doLoadFieldFirst(UserInterface::CField& game)
{
	
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	char** teren = game.getField();
	for (int i = 0; i < 37; i++)
	{

		for (int j = 0; j < 160; j++)
		{
			if (i == 0 && j == 0) conOut(0, 0) << teren[i][j];
			else conOut << teren[i][j];
		}
		conOut << "\n";
	}
	conOut(37, 130) << "Z - normal zombie";
	conOut(38, 130) << "B - buckethead zombie";
	conOut(39, 130) << "S - resurse de tip sun";
	conOut(40, 130) << "P - peashooter cu pret 150";
	conOut(41, 130) << "F - sunflower cu pret 250";
}

int main(void)
{
	int k = 0;
	int sun_rate = 0;
	int difficulty;
	cout << "To create a plant you have to double-click(select) from the first column from the left the plant you want\n\n";


	cout << "Please choose the difficulty 1, 2 or 3\n";
	cin >> difficulty;
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	//conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";
	static UserInterface::CField game = UserInterface::CField::getInstance(difficulty);
	CResursa collect_resurse;
	 
	doLoadFieldFirst(game);

	conOut(3, 1) << "SCORE  0";
	P_Z maingame;
	//maingame.add_zombie(*maingame.create_normal_zombie(difficulty, game));
	

	doLoadField(difficulty,game, maingame,sun_rate);
	
	while (true)
	{
		//doLoadingBar();
		//CResursa add_resurse;
		//add_resurse.newSun();
		

		doLoadField(difficulty,game, maingame,sun_rate);
		
		conOut(38, 2) << "resurse:" << game.get_resurse()<<"     ";
		std::string action = conIn.getUserActions();
		if (action != "")
		{
			conOut(41, 2) << action;
			std::size_t found = action.find("double clicked");
			if (found != std::string::npos)
			{
				
				int x = conIn.x; //coloana
				int y = conIn.y; //linia
				conOut(40, 2) << x<<" "<<y;

				switch (game.check_field(y/6, x/16))
				{
				case 'S':
					collect_resurse.collectSun(game, x / 16);
					game.increase_resurse();
					conOut(38, 2) << "resurse:" << game.get_resurse()<<"     ";
					char** teren;
					teren = game.getField();
					for (int i = 0; i < 6; i++)
					{
						for (int j = 17; j < 160; j++)
						{
							if (j == 17) conOut(i, 17) << teren[i][j];
							else conOut << teren[i][j];
						}

					}
					break;
				case 'F':
					if (y / 6 == 2)
						k = 2;
					break;
				case 'P':
					
					if (y / 6 == 1)
						k = 1;
					break;
				case ' ':
					if (k == 1)
					{

						maingame.add_plant(*maingame.create_peashooter(2, game, y / 6, x / 16));
						k = 0;
					}
					else if (k == 2)
					{
						maingame.add_plant(*maingame.create_sunflower(2, game, y / 6, x / 16));
						k = 0;
						sun_rate++;
					}
					break;
				}

			}
		}
	}

	return 0;
}

