#include "Teren.h"
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

}
void Teren::afiseaza_scena()
{
	//system("cls");
	conOut(2, 5) << "Score: ";
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


Teren::~Teren()
{

};