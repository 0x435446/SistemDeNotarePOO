#define _CRT_SECURE_NO_WARNINGS
#include "Teren.h"
#include "Sun.h"
#include <iostream>
#include <Windows.h>
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <string.h>
#include "SunFLower.h"
#include "PeaShooter.h"
#include "SnowPea.h"
#include "Wall_nut.h"
#include "CherryBomb.h"
#include "Zombi.h"
#include "Zombie.h"


#define for_i for(int i=0; i<DIM_X; i++)
#define for_j for(int j=0; j<DIM_Y; j++)
#define CHR_STANGA_SUS 201
#define CHR_STANGA_JOS 200
#define CHR_DREAPTA_SUS 187
#define CHR_DREAPTA_JOS 188
#define CHR_BARA_VERTICALA 186
#define CHR_BARA_ORIZONTALA 205

Teren::Teren()
{
	begin = std::chrono::system_clock::now();
	//to do 0: initializeaza matricea cu ' '(spatiu)
	for_i
		for_j
		scena[i][j] = ' ';
	//seteaza barele orizontale (sus si jos)
	for_j
		scena[0][j] = scena[DIM_X - 1][j] = CHR_BARA_ORIZONTALA;


	//seteaza barele verticale (stanga si dreapta)
	for_i
		scena[i][0] = scena[i][DIM_Y - 1] = CHR_BARA_VERTICALA;


	//seteaza colturile chenarului
	scena[0][0] = CHR_STANGA_SUS;
	scena[0][DIM_Y - 1] = CHR_DREAPTA_SUS;
	scena[DIM_X - 1][0] = CHR_STANGA_JOS;
	scena[DIM_X - 1][DIM_Y - 1] = CHR_DREAPTA_JOS;
	Sun *processedInput;
	for (int a = 1; a < 10; a++)
	{
		processedInput = new Sun((a*DIM_Y),DIM_X-1);
		SunArray[a] = processedInput;
	}
	afiseaza_scena();
	conOut(7, 4) << "Sun";
	conOut(8, 3) << "Flower";
	conOut(12, 4) << "Pea";
	conOut(13, 3) << "Shooter";
	conOut(17, 4) << "Snow";
	conOut(18, 4) << "Pea";
	conOut(22, 4) << "Wall";
	conOut(23, 4) << "Nut";
	conOut(27, 4) << "Cherry";
	conOut(28, 4) << "Bomb";

}

void Teren::afiseaza_scena()
{
	int a = 0, b = 0;
	for (int t = 0; t < 10; t++)
	{
		for (int u = 0; u < 6; u++)
		{
			for_i
			{
				for_j
				{
					conOut(a + i,b + j) << scena[i][j];
				}
			}
			a += DIM_X;
		}
		a = 0;
		b += DIM_Y;

	}
}

bool isNumber(char* s)
{
	if (strlen(s) == 0) return false;
	for (int i = 0; i < strlen(s); i++) {
		if ((s[i] >= '0' && s[i] <= '9') == false) {
			return false;
		}
	}
	return true;
}

void Teren::SunColect(std::string processedInput,Score& score)
{
	int a = NULL, b = NULL;

	if (strstr(processedInput.c_str(), "clicked") != 0)
	{
		char str[100];
		strcpy(str, processedInput.c_str());
		char pch[10];

			strcpy(pch, strtok(str, " ,("));

			while (pch != NULL)
			{
				if (isNumber(pch) == true)
				{
					a = atoi(pch);
				}
				strcpy(pch , strtok(NULL, " ,()"));
				if ((isNumber(pch) == true) && (a != NULL))
				{
					b = atoi(pch);
					break;
				}

			}
			for (int i = 1; i <= 9; i++)
			{
				if (SunArray[i]->set == true)
				{
					if ((SunArray[i]->x < a) && (a < SunArray[i]->x + DIM_Y))
						if ((SunArray[i]->y > b) && (b > SunArray[i]->y - DIM_X))
						{
							SunArray[i]->erase();
							SunArray[i]->set = false;
							score.setscore(25);
							score.printScor();
						}
					break;
				}
			}

		}
}

void Teren::printSun()
{
	auto end = std::chrono::system_clock::now();
	if (std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() > 5)
	{
		begin = std::chrono::system_clock::now();
		int x = rand() % 9 + 1;
		if (SunArray[x]->set == false)
		{
			SunArray[x]->set = true;
			SunArray[x]->print();
			
		}
	}
}

void Teren::plant(std::string processedInput, Score& score)
{
	int a = NULL, b = NULL;


	if (strstr(processedInput.c_str(), "clicked") != 0)
	{
		char str[100];
		strcpy(str, processedInput.c_str());
		char pch[10];

		strcpy(pch, strtok(str, " ,("));

		while (pch != NULL)
		{
			if (isNumber(pch) == true)
			{
				a = atoi(pch);
			}
			strcpy(pch, strtok(NULL, " ,()"));
			if ((isNumber(pch) == true) && (a != NULL))
			{
				b = atoi(pch);
				break;
			}

		}
		if ((0 < a) && (a < DIM_Y))
		{
			if ((2 * DIM_X > b) && (b > DIM_X))
			{
				while (true)
				{
					std::string processedInput = conIn.getUserActions();
					if (strstr(processedInput.c_str(), "clicked") != 0) {
						Plant *planta = new SunFlower(a, b);
						if (score.scor >= 10)
						{
							draw(processedInput, planta);
							score.setscore(-10);
							score.printScor();
							break;
						}
						else
							break;

					}
					else
						if (processedInput != "")
						{
							conOut(41, 2) << processedInput;

						}

				}
			}

			else
				if ((0 < a) && (a < DIM_Y))
				{
					if ((3 * DIM_X > b) && (b > DIM_X))
					{
						while (true)
						{
							std::string processedInput = conIn.getUserActions();
							if (strstr(processedInput.c_str(), "clicked") != 0) {
								Plant *planta = new PeaShooter(a, b);
								if (score.scor >= 10)
								{
									draw(processedInput, planta);
									score.setscore(-10);
									score.printScor();
									break;
								}
								else
									break;
							}
							else
								if (processedInput != "")
								{
									conOut(41, 2) << processedInput;

								}

						}
					}

					else if ((0 < a) && (a < DIM_Y))
					{

						if ((4 * DIM_X > b) && (b > DIM_X))
						{
							while (true)
							{
								std::string processedInput = conIn.getUserActions();
								if (strstr(processedInput.c_str(), "clicked") != 0) {
									Plant *planta = new SnowPea(a, b);
									if (score.scor >= 10)
									{
										draw(processedInput, planta);
										score.setscore(-10);
										score.printScor();
										break;
									}
									else
										break;
								}
								else
									if (processedInput != "")
									{
										conOut(41, 2) << processedInput;

									}

							}
						}

						else if ((0 < a) && (a < DIM_Y))
						{

						
							if ((5 * DIM_X > b) && (b > DIM_X))
							{
								while (true)
								{
									std::string processedInput = conIn.getUserActions();
									if (strstr(processedInput.c_str(), "clicked") != 0) {
										Plant *planta = new Wall_nut(a, b);
										if (score.scor >= 10)
										{
											draw(processedInput, planta);
											score.setscore(-10);
											score.printScor();
											break;
										}
										else
											break;
									}
									else
										if (processedInput != "")
										{
											conOut(41, 2) << processedInput;

										}

								}
							}
							else if ((0 < a) && (a < DIM_Y))
							{
								if ((6 * DIM_X > b) && (b > DIM_X))
								{
									while (true)
									{
										std::string processedInput = conIn.getUserActions();
										if (strstr(processedInput.c_str(), "clicked") != 0) {
											Plant *planta = new CherryBomb(a, b);
											if (score.scor >= 10)
											{
												draw(processedInput, planta);
												score.setscore(-10);
												score.printScor();
												break;
											}
											else
												break;
										}
										else
											if (processedInput != "")
											{
												conOut(41, 2) << processedInput;

											}

									}
								}

							}
						}
					}
				}
		}
	}
}


void Teren::draw(std::string process, Plant *planta)
{
	int a = NULL, b = NULL;

	if (strstr(process.c_str(), "clicked") != 0)
	{
		char str[100];
		strcpy(str, process.c_str());
		char pch[10];

		strcpy(pch, strtok(str, " ,("));

		while (pch != NULL)
		{
			if (isNumber(pch) == true)
			{
				a = atoi(pch);
			}
			strcpy(pch, strtok(NULL, " ,()"));
			if ((isNumber(pch) == true) && (a != NULL))
			{
				b = atoi(pch);
				break;
			}

		}
		planta->print(b, a);
	}

}


Teren::~Teren()
{
}
