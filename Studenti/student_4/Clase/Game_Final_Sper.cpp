#include "Game_Final_Sper.h"

void Game_Final_Sper::Game_Start()
{
	Select_Lvl Game1;
	Game1.Start_Lvl();
	cout << "Instructiuni :" << endl;
	cout << "Nu am reusit sa creez functionalitatea mouse`ului" << endl;
	cout << "Am inlocuit`o cu citirea de la tastatura" << endl;
	cout << "Cititi o cifra pentru linie,o cifra pentru planta,o cifra pentru pozitia pe linie" << endl;
	cout << "In cazul in care nu se poate adauga acolo,nu se va face adaugarea" << endl;
	cout << "Nume player : " << endl;
	string Name;
	cin >> Name;
	Game1.Set_Name(Name);
	cout << endl;
	cout << "Cititi de la tastatura cifra pentru nivel de dificultate:" << endl;
	cout << "1=Easy 2=Mediu 3=Hard" << endl;
	int X;
	cin >> X;
	system("cls");
	cout << "Have fun!" << endl;
	Sleep(3000);
	system("cls");
	Game1.Choose(X);
}
