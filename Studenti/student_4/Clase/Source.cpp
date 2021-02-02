#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
// Plants
#include "Plant_Peashooter.h"
#include "Plant_Cherry_Bomb.h"
#include "Plant_Wall_nut.h"
#include "Plant_Snow_Pea.h"
#include "Plant_Sunflower.h"
// Zombies
#include "Zm_Basic.h"
#include "Zm_BucketHead.h"
#include "Zm_PoleVaulting.h"
#include "Zm_Super.h"
//Entity
#include "Entity.h"
#include <iostream>
// LVL1 =EASY
#include "Easy.h"
#include <vector>
#include "Map.h"
#include "Sori.h"
#include "Select_Lvl.h"

//
//#include "ConsoleInput.h"
//#include "ConsoleOutput.h"
#include "Game_Final_Sper.h"
using namespace std;

//Consola* Consola::INstanta = NULL;




// int Verify(Entity* E1, Entity* E2) {
//	if (E1->Get_Name() != E2->Get_Name())
//		return 1;
//	else {
//		return 0;
//	}
//}
//
//void ItHurts(Entity *E1,Entity*E2) {
//	if (Verify(E1, E2) == 0) {
//
//	}
//	else
//	{
//		while (E1->Get_Hp() > 0 && E2->Get_Hp() > 0){
//			E1->Fight(*E2);
//			E2->Fight(*E1);
//		}
//	}
//}


int main() {


	//Doar aici  e cod


	Game_Final_Sper G1;
	G1.Game_Start();




	//Merge de aici
	/*Select_Lvl Game1;
	Game1.Start_Lvl();
	int x;
	cin >> x;
	Game1.Set_Name("Oliviu");
	Game1.Choose(x);*/
	// Pana aici
	/*Entity* Plant = new Plant_Peashooter(10,1000,0,"Plant",0);
	Entity* Zombie = new Zm_Basic(1,100,1,"Zombie",1);*/

	//Plant->Set_Hp(1000);
	//Plant->Set_Dmg(10);

	//Zombie->Set_Hp(100);
	//Zombie->Set_Dmg(1);

	/*cout << "P : " << Plant->Get_Hp() << "	Z : " << Zombie->Get_Hp() << endl;
	Plant->Fight(*Zombie);
	Zombie->Fight(*Plant);
	cout << "P : " << Plant->Get_Hp() << "	Z : " << Zombie->Get_Hp();

	Plant->Fight(*Plant);
	cout << "P : " << Plant->Get_Hp() << endl;*/
	
	
	//Asta merge
	/*Entity* Ground = new Zm_Basic(0, 0, 0, "Ground", 0);*/
	/*
	Entity* Linie[10];
	for(int i=0;i<10;i++){
		Linie[i] = Ground;
	}

	for (int i = 0; i < 10; i++)
		cout << Linie[i]->Get_Name() << endl;

	int coordonata = 9;
	cout << endl;
	Linie[9] = Zombie;*/
	//while (coordonata!=0) {
	//	//ItHurts(Linie[coordonata], Linie[coordonata - 1]);
	//	Linie[coordonata - 1] = Zombie;
	//	Linie[coordonata] = Ground;
	//	coordonata--;
	//	for (int i = 0; i < 10; i++)
	//		cout << Linie[i]->Get_Name() << endl;
	//	cout << endl;
	//}

	//for (int i = 0; i < 10; i++)
	//	cout << Linie[i]->Get_Name() << endl;
	//Pana aici

	/// Advance in array
	//Entity* Plant = new Plant_Peashooter(1, 100, 0, "Plant", 0);
	//Entity* Zombie = new Zm_Basic(1, 1000, 1, "Zombie", 1);
	//Entity* Ground = new Zm_Basic(0, 0, 0, "Ground", 0);
	//Entity* Linie[10];
	//for (int i = 0; i < 10; i++) {
	//	Linie[i] = Ground;
	//}

	//int coodonata = 9;
	//Linie[3] = Plant;
	//Linie[9] = Zombie;
	//
	//while (1 != 0 && Linie[1]->Get_Name() != Zombie->Get_Name()) {
	//	if (Linie[coodonata]->Get_Name() != Linie[coodonata - 1]->Get_Name() && Linie[coodonata]->Get_Name() != Ground->Get_Name())
	//	{
	//		
	//			ItHurts(Linie[coodonata], Linie[coodonata - 1]);
	//			if (Linie[coodonata]->Get_Hp() > 0) {
	//				Linie[coodonata - 1] = Linie[coodonata];
	//				Linie[coodonata] = Ground;
	//				coodonata--;
	//				for (int i = 0; i < 10; i++)
	//					cout << Linie[i]->Get_Name() << endl;
	//				cout << endl;
	//			}
	//		
	//		else
	//		{
	//			break;
	//		}
	//	}
	//}
	//cout << Linie[1]->Get_Hp();


	/*vector<Entity*> Zombies;
	Zombies.push_back(new Zm_Basic(10, 100, 1, "Zombie", 1));
	Zombies.push_back(new Zm_Basic(10, 100, 1, "Zombie", 1));*/
	//for (int i = 0; i < 2; i++) {
	//	cout << Zombies[i]->Get_Name();
	//}
	////////////////////////////////// DE AICI 8437561865836458165981645871
//	Easy L1(17);
//	L1.Start();
////	L1.Afis();
//	Entity* Plant = new Plant_Peashooter(25, 11, 0, "Plant", 0);
//	Entity* Plant2 = new Plant_Peashooter(25, 11, 1,"Plant", 0);
//	Entity* Zombie = new Zm_BucketHead(10, 100, 1, "Zombie", 1);
//	Entity* Cherry = new Plant_Cherry_Bomb(1000, 100, 1,"Plant", 0);
//	Entity* Cherry2 = new Plant_Cherry_Bomb(1000, 100, 1,"Plant", 0);
//	Entity* Pole = new Zm_PoleVaulting(10, 1000, 1, "Zombie", 2);
//	Entity* Snow = new Plant_Snow_Pea(1, 10, 0, "Plant", 1);
//	Entity* Flower = new Plant_Sunflower(0,10,5,"Plant",0);
//	//L1.Add(Plant, 0);
//	//L1.Add(Plant2, 1);
//	
//	//L1.Add(Snow, 1);
//	//L1.Add(Pole, 8);
//	//L1.Add(Cherry2, 5);
////	L1.Add(Plant2, 3);
////	L1.Add(Zombie, 8);
//	L1.Add(Flower, 0);
//	//L1.Add(Zombie, 8);
//	//L1.Add(Zombies[0], 9);
//	L1.Start_Plants();
//	L1.Start_Zm();
//	//FAZA CU SOARELE
//	Sori S1;
//	S1.Start_Sori();
//	S1.Set_Sun();
////L1.Add_Zm();
//	int ok = 0;
//	L1.Add(Zombie, 8);
//	while (L1.Lose() == 0) {
//		Map::Mapa();
//		L1.Afisez_Fain(0);
//		//Umblu de aici
//		if (ok % 2 == 0) {
//			Buzunar::Add_Resources(25);
//			L1.Moneeey();
//			
//		}
//		if (ok % 3 == 0)//Sa bage cate un soare random;
//			S1.Generate_Rnadom();
//		ok++;
//		//Merge cu tastatura
//		int Poz;
//		cin >> Poz;
//		S1.Click_Pe_Soare(Poz);
//		//Sa afiseze soarele
//		S1.Afisez_Soarele();
//		string MonyMony = to_string(Buzunar::Get_Resources());
//		string Bani = "Bani:";
//		Consola::gotoYXMov(105, 5, Bani);
//		Consola::gotoYXVerde(110, 5, MonyMony);
//		//Pana aici
//		L1.ItHurts_For_Zm();
//		L1.Clear();
//		Scor::Afis_Scor();
//		Sleep(500);
//	//	L1.Afis();
//		L1.Afisez_Fain(0);
//		 
//		Sleep(500);
//		L1.ItHurts_For_Plants();
//		Sleep(500);
//		L1.Clear();
//	
//	//	L1.Afis();
//		L1.Afisez_Fain(0);
//		 
//
//		L1.Deplasez();
//		Sleep(500);
//	//	L1.Afis();
//		L1.Afisez_Fain(0);
//		int Choose;
//		int Indexare;
//		cin >> Choose>>Indexare;
//		
//		L1.Add_Final(Choose, Indexare);
//		system("cls");
//		/*if (ok % 1 == 0)
//			L1.Add_Zm(); // Ca sa nu mai genereze singur
//		ok++;*/
//		
//		 
//	}
	////// PANA AICI MAN!!!!%$#@$^$^$$!^

	_getch();
	return 0;
}