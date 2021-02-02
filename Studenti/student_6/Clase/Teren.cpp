#include "Teren.h"
#include"ConsoleInput.h"
#include"ConsoleOutput.h"


Teren::Teren() :
	scena_scor(), scena_sori(), scena_plante(), scena1(), scena2(), scena3()
{
}

void Teren::gotoXY(int x, int y)
{
	COORD coord = { x, y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Teren::initializeaza_scena_scor()
{
	Log::get_instance().logevent("Se initializeza chenarul pentru scor\n");
	for_j_scor
		scena_scor[0][j] = scena_scor[DIM_X_scor - 1][j] = CHR_BARA_ORIZONTALA;
	for_i_scor
	{
		scena_scor[i][0] = scena_scor[i][DIM_Y_scor - 1] = CHR_BARA_VERTICALA;
	}

	scena_scor[0][0] = CHR_STANGA_SUS;
	scena_scor[0][DIM_Y_scor - 1] = CHR_DREAPTA_SUS;
	scena_scor[DIM_X_scor - 1][0] = CHR_STANGA_JOS;
	scena_scor[DIM_X_scor - 1][DIM_Y_scor - 1] = CHR_DREAPTA_JOS;
	
}

void Teren::afiseaza_scena_scor()
{
	Log::get_instance().logevent("Se afiseaza scena pentru scor\n");
	for_i_scor
	{
		for_j_scor
		{
			printf("%c",scena_scor[i][j]);
		}
		printf("\n");
	}
}


void Teren::initializeaza_scena_sori()
{
	Log::get_instance().logevent("Se initializeza chenarul pentru sori\n");
	for_j_sori
		scena_sori[0][j] = scena_sori[DIM_X_sori - 1][j] = CHR_BARA_ORIZONTALA;

	for_i_sori
	{ 
		scena_sori[i][0] = scena_sori[i][DIM_Y_sori - 1] = CHR_BARA_VERTICALA;
	for (int i = 1; i < 6; i++)
	{
		if (i % 2 != 0)
		{
			scena_sori[i][15] = CHR_BARA_VERTICALA;
		}
		else
		{
			scena_sori[i][15] = ' ';
		}
	}
	for (int i = 1; i < 6; i++)
	{
		if (i % 2 != 0)
		{
			scena_sori[i][30] = CHR_BARA_VERTICALA;
		}
		else
		{
			scena_sori[i][30] = ' ';
		}
	}
	for (int i = 1; i < 6; i++)
	{
		if (i % 2 != 0)
		{
			scena_sori[i][45] = CHR_BARA_VERTICALA;
		}
		else
		{
			scena_sori[i][45] = ' ';
		}
	}
	for (int i = 1; i < 6; i++)
	{
		if (i % 2 != 0)
		{
			scena_sori[i][60] = CHR_BARA_VERTICALA;
		}
		else
		{
			scena_sori[i][60] = ' ';
		}
	}
	for (int i = 1; i < 6; i++)
	{
		if (i % 2 != 0)
		{
			scena_sori[i][75] = CHR_BARA_VERTICALA;
		}
		else
		{
			scena_sori[i][75] = ' ';
		}
	}
	for (int i = 1; i < 6; i++)
	{
		if (i % 2 != 0)
		{
			scena_sori[i][90] = CHR_BARA_VERTICALA;
		}
		else
		{
			scena_sori[i][90] = ' ';
		}
	}
	for (int i = 1; i < 6; i++)
	{
		if (i % 2 != 0)
		{
			scena_sori[i][105] = CHR_BARA_VERTICALA;
		}
		else
		{
			scena_sori[i][105] = ' ';
		}
	}
	for (int i = 1; i < 6; i++)
	{
		if (i % 2 != 0)
		{
			scena_sori[i][120] = CHR_BARA_VERTICALA;
		}
		else
		{
			scena_sori[i][120] = ' ';
		}
	}
	}

	scena_sori[0][0] = CHR_STANGA_SUS;
	scena_sori[0][DIM_Y_sori - 1] = CHR_DREAPTA_SUS;
	scena_sori[DIM_X_sori - 1][0] = CHR_STANGA_JOS;
	scena_sori[DIM_X_sori - 1][DIM_Y_sori - 1] = CHR_DREAPTA_JOS;

}


void Teren::afiseaza_scena_sori()
{
	Log::get_instance().logevent("Se afiseaza chenarul pentru sori\n");

	for_i_sori
	{
		for_j_sori
		{
			gotoXY(j + 16,i);
			printf("%c",scena_sori[i][j]);
		}
		printf("\n");
	}
}


void Teren::initializeaza_scena_plante()
{
	Log::get_instance().logevent("Se initializeza chenarul pentru plante\n");

	for_j_plante
	{ 
		scena_plante[0][j] = scena_plante[DIM_X_plante - 1][j] = CHR_BARA_ORIZONTALA;
	
		for (int i = 0; i < 15; i++)
		{
			if (i % 2 == 0)
			{
				scena_plante[4][i] = CHR_BARA_ORIZONTALA;
			}
			else
			{
				scena_plante[4][i] = ' ';
			}
		}
		for (int i = 0; i < 15; i++)
		{
			if (i % 2 == 0)
			{
				scena_plante[9][i] = CHR_BARA_ORIZONTALA;
			}
			else
			{
				scena_plante[9][i] = ' ';
			}
		}
		for (int i = 0; i < 15; i++)
		{
			if (i % 2 == 0)
			{
				scena_plante[14][i] = CHR_BARA_ORIZONTALA;
			}
			else
			{
				scena_plante[14][i] = ' ';
			}
		}
		for (int i = 0; i < 15; i++)
		{
			if (i % 2 == 0)
			{
				scena_plante[19][i] = CHR_BARA_ORIZONTALA;
			}
			else
			{
				scena_plante[19][i] = ' ';
			}
		}
	}

	for_i_plante
	{
		scena_plante[i][0] = scena_plante[i][DIM_Y_plante - 1] = CHR_BARA_VERTICALA;
		scena_plante[2][7] = 'P';
		scena_plante[7][7] = 'S';
		scena_plante[12][7] = 'A';
		scena_plante[17][7] = 'B';
		scena_plante[22][7] = 'C';
	}

	scena_plante[0][0] = CHR_STANGA_SUS;
	scena_plante[0][DIM_Y_plante - 1] = CHR_DREAPTA_SUS;
	scena_plante[DIM_X_plante - 1][0] = CHR_STANGA_JOS;
	scena_plante[DIM_X_plante - 1][DIM_Y_plante - 1] = CHR_DREAPTA_JOS;
}

void Teren::afiseaza_scena_plante()
{
	Log::get_instance().logevent("Se afiseaza chenarul pentru plante\n");

	for_i_plante
	{
		for_j_plante
		{
			gotoXY(j,i + 7);
			printf("%c",scena_plante[i][j]);
		}
		printf("\n");
	}
}

void Teren::initializeaza_scena1()
{
	for_j_scena1
		scena1[0][j] = scena1[DIM_X_scena1 - 1][j] = CHR_BARA_ORIZONTALA;

	for_i_scena1
		scena1[i][0] =  CHR_BARA_VERTICALA;


	scena1[0][0] = CHR_STANGA_SUS;
	scena1[DIM_X_scena1 - 1][0] = CHR_STANGA_JOS;
}

void Teren::afiseaza_scena1()
{
	
	for_i_scena1
	{
		for_j_scena1
		{
			gotoXY(j + 16,i + 16);
			printf("%c",scena1[i][j]);
		}
		printf("\n");
	}
}

void Teren::initializeaza_scena2()
{
	for_j_scena2
	{ 
		scena2[0][j] = scena2[DIM_X_scena2 - 1][j] = CHR_BARA_ORIZONTALA;
		scena2[5][j] = CHR_BARA_ORIZONTALA;
		scena2[10][j] = CHR_BARA_ORIZONTALA;
	}

	for_i_scena2
		scena2[i][0]  = CHR_BARA_VERTICALA;

	scena2[0][0] = CHR_STANGA_SUS;
	scena2[DIM_X_scena2 - 1][0] = CHR_STANGA_JOS;
}

void Teren::afiseaza_scena2()
{
	for_i_scena2
	{
		for_j_scena2
		{
			gotoXY(j + 16,i + 11);
			printf("%c",scena2[i][j]);
		}
		printf("\n");
	}
}

void Teren::initializeaza_scena3()
{
	for_j_scena3
	{
		scena3[0][j] = scena3[DIM_X_scena3 - 1][j] = CHR_BARA_ORIZONTALA;
		scena3[4][j] = scena3[DIM_X_scena3 - 1][j] = CHR_BARA_ORIZONTALA;
		scena3[9][j] = scena3[DIM_X_scena3 - 1][j] = CHR_BARA_ORIZONTALA;
		scena3[14][j] = scena3[DIM_X_scena3 - 1][j] = CHR_BARA_ORIZONTALA;
		scena3[19][j] = scena3[DIM_X_scena3 - 1][j] = CHR_BARA_ORIZONTALA;
	}

	for_i_scena3
		scena3[i][0] = CHR_BARA_VERTICALA;

	scena3[0][0] = CHR_STANGA_SUS;
	scena3[DIM_X_scena3 - 1][0] = CHR_STANGA_JOS;
}

void Teren::afiseaza_scena3()
{
	for_i_scena3
	{
		for_j_scena3
		{
		gotoXY(j + 16,i + 7);
			printf("%c",scena3[i][j]);
		}
		printf("\n");
	}
}

void Teren::afiseaza_scena(int i)
{
	initializeaza_scena_scor();
	afiseaza_scena_scor();
	initializeaza_scena_sori();
	afiseaza_scena_sori();
	initializeaza_scena_plante();
	afiseaza_scena_plante();
	if (i == 1)
	{
		initializeaza_scena1();
		afiseaza_scena1();
	}
	if (i == 2)
	{
		initializeaza_scena2();
		afiseaza_scena2();
	}
	if (i == 3)
	{
		initializeaza_scena3();
		afiseaza_scena3();
	}
}

Teren::~Teren()
{
}
