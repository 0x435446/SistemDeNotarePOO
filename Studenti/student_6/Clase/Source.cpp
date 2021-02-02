#define _CRT_SECURE_NO_WARNINGS
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include"Sun.h"
#include"Teren.h"
#include"Zombie.h"
#include"ZombieNormal.h"
#include"Plante.h"
#include"Peashooter.h"
#include"Coordonate.h"
#include"SunFlower.h"
#include"Pea.h"
#include"BucketHeadZombie.h"
#include"Jucator.h"
#include <time.h>
#include <chrono>
#include<string>
#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5

using namespace std::chrono;

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

void doLoadingScreen()
{

	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";
	time_t start = time(NULL);
	time_t stop = time(NULL);
	while (stop - start < 3)
	{
		doLoadingBar();
		stop = time(NULL);
	}
	
	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "                                       ";
	for (int i = 0; i < 5; i++)
	{
		conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION + i * COL_DISTANCE_BETWEEN_STARS) << " ";
	}

}

int scor = 0;
int x_copie=0;
int xs_copie = 0;
int rate = 3000;
int ataca_x;
int ataca_y;
int ok_ataca=0;

void do_action(const std::string &action, Teren t,Sun s,SunFlower sf,Peashooter peashooter,Pea pea)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	int x;
	int y;
	Coordonate c(action);
	x = c.cx;
	y = c.cy;
	if ((x == 24 || x == 54 || x == 84 || x == 114 || x == 144) && y == 3)
	{
		s.colectare_sori(t, x, y);
		scor +=50;
	}

	
	if ((x == 7 && y == 9) && peashooter.get_cost() <= scor)
	{
		peashooter.colectare_plante(t, x, y);
		x_copie = 1;
	}
	if (scor >= peashooter.get_cost())
	{
		
		if ((y == 8 || y == 13 || y == 23 || y == 28 || y == 18) && (x_copie == 1))
		{
			if (peashooter.get_cost() == scor)
			{
				scor = 0;
			}
			else
			{
				scor -= peashooter.get_cost();
			}
			peashooter.plaseaza_plante(t, x, y);
			x_copie = 0;
			ok_ataca = 1;
			ataca_x = x;
			ataca_y = y;
		}
	}

	if ((x == 7 && y == 14) && sf.get_cost() <= scor)
	{
		sf.colectare_plante(t, x, y);
		xs_copie = 1;
	}
	if (scor >= sf.get_cost())
	{
		if ((y == 9 || y == 13 || y == 23 || y == 28 || y == 18) && (xs_copie == 1))
		{
			if (sf.get_cost() == scor)
			{
				scor = 0;
			}
			else
			{
				scor -= sf.get_cost();
			}
			sf.plaseaza_plante(t, x, y);
			xs_copie = 0;
			if (rate >=1000)
			{
				rate -= 100;
			}
		}
	}
}

int main(void)
{
	Teren t;
	t.gotoXY(50, 10);
	char nume[100];
	char parola[100];
	printf("Nume: ");
	scanf("%s", &nume);
	t.gotoXY(50, 11);
	printf("Parola: ");
	scanf("%s", &parola);
	Jucator jucator(nume,parola);
	jucator.salveaza_datele();
	system("cls");


	Log::get_instance().logevent("Joc nou\n\n\n");
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	
	
	ZombieNormal z(600, 1000);
	BucketHeadZombie b(500, 1000);
	Sun s;
	Peashooter peashooter(100,1);
	SunFlower sf(50,1);
	Pea pea(20);
	int i=0;
	int castigat = 0;
	int pierdut ;
	
	while (i<3)
	{
		ok_ataca = 0;
		if (i == 0)
		{
			doLoadingScreen();
		}
		else
		{
			Sleep(3000);
		}
		t.gotoXY(0, 0);
		t.afiseaza_scena(i+1);
		conOut(2, 3) << "Scor:";
		scor = 0;

		int rez = 0;
		int ok = 1;
		while (ok==1)
		{

			s.set_location(t,rate);
			if (i == 0)
			{
				if (z.place_zombie1() == 0)
				{
					ok = 0;
				}
			}
			if (i == 1)
			{
				if (z.place_zombie2() == 0)
				{
					ok = 0;
				}
			}
			if (i == 2)
			{
				if (b.place_zombie3() == 0)
				{
					ok = 0;
				}
			}
			std::string action = conIn.getUserActions();
			if (action != "")
			{
				conOut(10, 6) << 100;
				conOut(15, 6) << 50;
				conOut(41, 2) << action;
				conOut(4, 4) << " ";
				conOut(4, 5) << " ";
				conOut(4, 6) << " ";
				conOut(4, 7) << " ";
				conOut(4, 5) << scor;
				do_action(action, t, s,sf, peashooter,pea);
				rez++;
			}
			
			if (ok_ataca == 1)
			{
				pea.ataca(ataca_y, ataca_x);
			}
			if ((z.get_rezistenta() < rez)&&(i==0||i==1))
			{
				castigat++;
				ok = 0;
			}
			if ((b.get_rezistenta() < rez) && (i == 2))
			{
				castigat++;
				ok = 0;
			}
		}
		i++;
	}
	system("cls");

	pierdut = 3 - castigat;
	if (pierdut > castigat) 
	{
		conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Joc pierdut";
		Sleep(3000);
	}
	else
	{
		conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Joc castigat";
		Sleep(3000);
	}
	jucator.salveaza_scor(castigat);

	conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Jocul s-a terminat";
	_getch();


	return 0;
}

