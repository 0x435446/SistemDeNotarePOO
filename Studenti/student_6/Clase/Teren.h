#pragma once
#include <stdio.h>
#include <Windows.h>
#include <WinBase.h>
#include <conio.h>
#include<time.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include"Log.h"

#define DIM_X_scor 7
#define DIM_Y_scor 15
#define DIM_X_sori 7
#define DIM_Y_sori 135
#define DIM_X_plante 25
#define DIM_Y_plante 15

#define DIM_X_scena1 5
#define DIM_Y_scena1 135
#define DIM_X_scena2 15
#define DIM_Y_scena2 135
#define DIM_X_scena3 25
#define DIM_Y_scena3 135

#define CHR_STANGA_SUS 201
#define CHR_STANGA_JOS 200
#define CHR_DREAPTA_SUS 187
#define CHR_DREAPTA_JOS 188
#define CHR_BARA_VERTICALA 186
#define CHR_BARA_ORIZONTALA 205

#define for_i_scor for(int i=0;i<DIM_X_scor;i++)
#define for_j_scor for(int j=0;j<DIM_Y_scor;j++)

#define for_i_sori for(int i=0;i<DIM_X_sori;i++)
#define for_j_sori for(int j=0;j<DIM_Y_sori;j++)

#define for_i_plante for(int i=0;i<DIM_X_plante;i++)
#define for_j_plante for(int j=0;j<DIM_Y_plante;j++)

#define for_i_scena1 for(int i=0;i<DIM_X_scena1;i++)
#define for_j_scena1 for(int j=0;j<DIM_Y_scena1;j++)

#define for_i_scena2 for(int i=0;i<DIM_X_scena2;i++)
#define for_j_scena2 for(int j=0;j<DIM_Y_scena2;j++)

#define for_i_scena3 for(int i=0;i<DIM_X_scena3;i++)
#define for_j_scena3 for(int j=0;j<DIM_Y_scena3;j++)



class Teren
{
public:
	char scena_scor[DIM_X_scor][DIM_Y_scor];
	char scena_sori[DIM_X_scor][DIM_Y_sori];
	char scena_plante[DIM_X_plante][DIM_Y_plante];
	char scena1[DIM_X_scena1][DIM_Y_scena1];	
	char scena2[DIM_X_scena2][DIM_Y_scena2];
	char scena3[DIM_X_scena3][DIM_Y_scena3];
public:
	Teren();
	~Teren();

	void gotoXY(int, int);

	void initializeaza_scena_scor();
	void afiseaza_scena_scor();

	void initializeaza_scena_sori();
	void afiseaza_scena_sori();

	void initializeaza_scena_plante();
	void afiseaza_scena_plante();

	void initializeaza_scena1();
	void afiseaza_scena1();

	void initializeaza_scena2();
	void afiseaza_scena2();

	void initializeaza_scena3();
	void afiseaza_scena3();

	void afiseaza_scena(int);
};