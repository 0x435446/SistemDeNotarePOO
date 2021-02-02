#include "Sori.h"

void Sori::Start_Sori()
{
	for (int i = 0; i < 9; i++) {
		Multi_Sori.push_back(Sun(25, 0));
	}
}

void Sori::Generate_Rnadom()
{
	srand(time(NULL));
	int r = rand()%9;
	Multi_Sori[r].Da_Sau_Nu = 1;
}

void Sori::Click_Pe_Soare(int x)
{	
	if (x < 9 && x>=0) {
		if (Multi_Sori[x].Da_Sau_Nu == 1) {
			Buzunar::Add_Resources(Multi_Sori[x].Give_Resource());
			Multi_Sori[x].Da_Sau_Nu = 0;
		}
	}
}

void Sori::Set_Sun()
{
	for (int i = 0; i < 9; i++)
		Multi_Sori[i].Da_Sau_Nu = 0;
}

void Sori::Afisez_Soarele()
{
	for (int i = 0; i < 9; i++) {
		if (Multi_Sori[i].Da_Sau_Nu == 1)
			Consola::gotoYXGalben(i*10+15, 3, "O");
		else
		{
			Consola::gotoYXGalben(i * 10 + 15, 3, " ");
		}
	}
}