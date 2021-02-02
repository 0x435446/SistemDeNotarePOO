#pragma once
#include "Entity.h"
//Zm
#include "Zm_Basic.h"
#include "Zm_PoleVaulting.h"
#include "Zm_BucketHead.h"
#include "Zm_Super.h"
//Plants
#include "Plant_Peashooter.h"
#include "Plant_Snow_Pea.h"
#include "Plant_Sunflower.h"
#include "Plant_Wall_nut.h"
#include "Plant_Cherry_Bomb.h"
//Recuzita
#include "Buzunar.h"
#include "Consola.h"
#include "Scor.h"
//STL
#include <string>
#include <vector>
using namespace std;

class Easy{

	private:
		int Index;
		Entity* Linie[12];
		Entity* Ground = new Zm_Basic(0, 0, 0, "Ground", 0);
		Entity* Plant = new Plant_Peashooter(0, 0, 0, "Plant", 0);
		Entity* Zombie = new Zm_Basic(0,0, 0, "Zombie",0);
		vector<Entity*> Zombies; int Mda_Zm=0;
		vector<Entity*> Plant_PeaShooter;  int Mda_PeaShooter=0;
		vector<Entity*> Plant_Pea_Snow; int Mda_Pea_Snow=0;
		vector<Entity*> Plant_Bombs; int Mda_Bombs=0;
		vector<Entity*> Plant_Wallnuts; int Mda_Wallnuts=0;
		vector<Entity*> Plant_SunFlower; int Mda_SunFlower = 0;
	public:
		Easy() {};
		Easy(int Index) {
			this->Index = Index;
			
		};
		void Set_index(int x) {
			this->Index = x;
		}
		// Verific daca cele 2 entitati sunt diferite(Exclude Ground)	GATA
		int Verify(Entity* E1, Entity* E2) {
		if (E1->Get_Name() != E2->Get_Name() && E1->Get_Name() != Ground->Get_Name() && E2->Get_Name() != Ground->Get_Name()){
			return 1;
		}
		else {
			return 0;
		}
	}
	
		//Lupta melee
		void ItHurts(Entity* E1, Entity* E2) {
		if (Verify(E1, E2) == 0) {

		}
		else
		{
			while (E1->Get_Hp() > 0 && E2->Get_Hp() > 0) {
				E1->Fight(*E2);
				E2->Fight(*E1);
			}
		}
	}
		//Add unitate de lupta pe pozitia X		GATA
		void Add(Entity* E,int index) {
			if (Linie[index]->Get_Name() != Plant->Get_Name() && Linie[index]->Get_Name() != Zombie->Get_Name()) {
				Linie[index] = E;
			}
		}
		//START PLANTS
		void Start_Plants() {
			for (int i = 0; i < 100; i++) {
				Plant_PeaShooter.push_back(new Plant_Peashooter(20, 19, 0, "Plant", 0));
				Plant_Pea_Snow.push_back(new Plant_Snow_Pea(15, 19, 0, "Plant", 1));
				Plant_Bombs.push_back(new Plant_Cherry_Bomb(1000, 100, 1, "Plant", 0));
				Plant_Wallnuts.push_back(new Plant_Wall_nut(0, 50, 0, "Plant", 0));
				Plant_SunFlower.push_back(new Plant_Sunflower(0, 10, 5, "Plant", 0));
			}
		}
		
		void Plante_Stanga() {
			Consola::gotoYXRosu(5, 7, "Pe");
			Consola::gotoYXRosu(5, 12,  "Su");
			Consola::gotoYXRosu(5, 17, "Ch");
			Consola::gotoYXMov(5,  22, "Wa");
			Consola::gotoYXMov(5,  27, "Sn");
		}

		//Plantele dau de la distanta     GATA
		void ItHurts_For_Zm() {
		//cout << "ItHurts_For_Zm" << endl;
			for (int i = 0; i < 8; i++) {
				if (Linie[i]->Get_Name() == Plant->Get_Name()) {
					for (int j = i + 1; j < 9; j++) {
						if (Linie[i]->Get_Jump() != 5) {
							//Aici modific
							if (Linie[i]->Get_Jump() == 1) {
								int Stop = 1;
								if (j = i + 1) {
									if (Linie[i]->Get_Jump() == 1 && Linie[i]->Get_Name() == Plant->Get_Name()) {
										Linie[i]->Fight(*Linie[j]);
										Stop = 0;
									}
								}
								if (Stop == 0)
									break;//Pana aici
							}
							//Pana aici
							int B = 1;
							if (Verify(Linie[i], Linie[j]) == 0) {
								//In cazul asta nu face nimic
							}
							else
							{
								if (Linie[i]->Get_Jump() != 1) {				//Am adaugat acest if dat naibii
									Linie[i]->Fight(*Linie[j]);
									if (Linie[i]->Get_Speed() != 0)//De aici pana aici am modificat ASTA E BUN
										Linie[j]->Set_Speed(1);	   //pana aici am modificat

									B = 0;
								}
								/*if (Linie[i]->Get_Jump() == 5) {

								}*/
							}
							if (B == 0)
								break;
						}
					}
				}
			
			}
		}
		//Verific existenta Sunflower
		void Moneeey() {
			for (int i = 0; i < 9; i++)
				if (Linie[i]->Get_Jump() == 5 )
					Buzunar::Add_Resources(25);
		}
		//Adaug plante pe pozitiile la care vreau
		void Add_Position(Entity* E, int index, int Cost) {
			if (Buzunar::Verify(Cost) == 1)
			{
				Buzunar::Pay_Resources(Cost);
				this->Add(E, index);
			}
		}

		void Add_Final(int Choose, int Index) {
			if (Choose == 1) {
				Add_Position(Plant_PeaShooter[Plant_PeaShooter.size() - 1 - Mda_PeaShooter], Index, 100);
				Mda_PeaShooter++;
			}
			if (Choose == 2) {
				Add_Position(Plant_SunFlower[Plant_SunFlower.size() - 1 - Mda_SunFlower], Index, 50);
				Mda_SunFlower++;
			}
			if (Choose == 3) {
				Add_Position(Plant_Bombs[Plant_Bombs.size() - 1 - Mda_Bombs], Index, 150);
				Mda_Bombs++;
			}
			if (Choose == 4) {
				Add_Position(Plant_Wallnuts[Plant_Wallnuts.size() - 1 - Mda_Wallnuts], Index, 50);
				Mda_Wallnuts++;
			}
			if (Choose == 5) {
				Add_Position(Plant_Pea_Snow[Plant_Pea_Snow.size() - 1 - Mda_Pea_Snow], Index, 175);
				Mda_Pea_Snow++;
			}
		}


		//Capat de linie   GATA//Am modificat de la i=1 la i =0
		int Lose() {
			if (Linie[0]->Get_Name() == Zombie->Get_Name()){
				Consola::gotoYXMov(30, 35, "Game_Over");
				return 1;
			}
			else{
				return 0;
			}
		}

		//Aranjez mapa     GATA
		void Start() {
		for (int i = 0; i < 11; i++){
			Linie[i] = Ground;
		}
	}
		void Afis() {
			for (int i = 0; i < 9; i++) {
				cout << Linie[i]->Get_Name() <<"	HP: "<<Linie[i]->Get_Hp()<<"	Dmg:"<<Linie[i]->Get_Dmg()<< endl;
			}
			cout << endl << endl;
		}
		//			MODIFIC		MODIFIC MODIFICMODIFICMODIFIC MODIFIC MODIFIC											MODIFIC 12 e bine pentru index
		void Afisez_Fain(int Index) {
			static int col = 0;;
			for (int i = 0; i < 9; i++) {
				/*if (Linie[i]->Get_Name() == Ground->Get_Name()) //Asa era initial
					Consola::gotoYXVerde(i*10+15, this->Index, "G");
				if (Linie[i]->Get_Name() == Plant->Get_Name())
					Consola::gotoYXMov(i * 10+15, this->Index, "P");
				if (Linie[i]->Get_Name() == Zombie->Get_Name())
					Consola::gotoYXVerde(i * 10+15, this->Index, "Z");*/

				//Ground ramane neschimbat
				if (Linie[i]->Get_Name() == Ground->Get_Name()) 
					Consola::gotoYXVerde(i * 10 + 15, this->Index, "Gr");
				//Afisez tipurile de Zm
				if (Linie[i]->Get_Name() == Zombie->Get_Name()) {
					int ok = 1;
					if (Linie[i]->Get_Dmg() == 19) {
						Consola::gotoYXVerde(i * 10 + 15, this->Index, "Sp");
						ok = 0;
					}
					if(Linie[i]->Get_Dmg()<19 && Linie[i]->Get_Speed()>1){
						Consola::gotoYXVerde(i * 10 + 15, this->Index, "Pl");
						ok = 0;
					}
					if (Linie[i]->Get_Dmg() < 19 && Linie[i]->Get_Hp() == 150){
						Consola::gotoYXVerde(i * 10 + 15, this->Index, "Bk");
						ok = 0;
					}
					if(Linie[i]->Get_Dmg()==10 && Linie[i]->Get_Hp()==100 && Linie[i]->Get_Speed()>1)
						Consola::gotoYXVerde(i * 10 + 15, this->Index, "Zm");
				}

				if (Linie[i]->Get_Name() == Plant->Get_Name()){
			
					if (Linie[i]->Get_Dmg() > 100)
					{
						Consola::gotoYXMov(i * 10 + 15, this->Index, "Ch");
				
					}
					if (Linie[i]->Get_Dmg() == 0 && Linie[i]->Get_Jump() == 5) {
						Consola::gotoYXMov(i * 10 + 15, this->Index, "Su");
					
					}
					if (Linie[i]->Get_Dmg() == 0 && Linie[i]->Get_Jump() == 0) {
						Consola::gotoYXMov(i * 10 + 15, this->Index, "Wa");
				
					}
					if (Linie[i]->Get_Speed() > 0) {
						Consola::gotoYXMov(i * 10 + 15, this->Index, "Sn");
					}
					if (Linie[i]->Get_Hp()==19 && Linie[i]->Get_Dmg()==20) {
						Consola::gotoYXMov(i * 10 + 15, this->Index, "Pe");
					}
				}
					

			}
			col = col *10;
		}										
		//Curat mapa	   GATA
		void Clear() {
			//				cout << "Clear" << endl;
			for (int i = 0; i < 9; i++) {
				if (Linie[i]->Get_Hp() == 0 || Linie[i]->Get_Hp() < 0) {
					if (Linie[i]->Get_Name() == Zombie->Get_Name()) {
						//if(Zombies.empty()==1)
						Scor::Increase_Scor(20);
						Zombies.pop_back();
					}
					Linie[i] = Ground;
				}
			}
		}

		// Zombie cand ajung langa planta dau un basic
		void ItHurts_For_Plants() {
		//			cout << "ItHurts_For_Plants" << endl;//Am modificat de la i=1 la i =0
			for (int i = 0; i < 8; i++) {
				if (Linie[i]->Get_Name() == Plant->Get_Name() && Linie[i + 1]->Get_Name() == Zombie->Get_Name()) {
					Linie[i + 1]->Fight(*Linie[i]);
				}
			}
		}
		//Start la vectori												MODIFIC
		void Start_Zm() {
			for (int i = 0; i < 100;i++) {
				if (i % 5 == 0 || i%5==1 || i % 5 == 3) {
					Zombies.push_back(new Zm_Basic(10, 100, 0, "Zombie", 1));
				}
				if (i % 5 == 2) {//Bucket
					Zombies.push_back(new Zm_BucketHead(9, 150, 0, "Zombie", 1));
				}
				if (i % 5 == 4) {//Pole
					Zombies.push_back(new Zm_PoleVaulting(10, 100, 0, "Zombie", 2));
				}
				if (i % 10 == 0) {//Zm super
					Zombies.push_back(new Zm_Super(19, 150, 0, "Zombie", 2));
				}
			}
		}                     
		//Adauga automat												MODIFIC
		void Add_Zm() {
			static int mda = 0;
			if (Linie[9]->Get_Name() == Ground->Get_Name())
				this->Add(Zombies[Zombies.size()-99+mda], 9);
			mda++;
		}    
		//Deplaseaza automat
		void Deplasez() {
		//	cout << "Deplasez" << endl; //Am modificat de la i=1 la i =0
			for (int i = 0; i < 9; i++) {
				if (Linie[i + 1]->Get_Name() == Zombie->Get_Name() && Linie[i]->Get_Name() == Ground->Get_Name() && Linie[i + 1]->Get_Speed() == 1) {
					Linie[i] = Linie[i + 1];
					Linie[i + 1] = Ground;
				}
				int boolean = 1;
				if (Linie[i + 2]->Get_Name() == Zombie->Get_Name() && Linie[i]->Get_Name() == Ground->Get_Name() && Linie[i + 2]->Get_Speed() > 1) {
					Linie[i] = Linie[i + 2];
					Linie[i + 2] = Ground;
					boolean = 0;
				}
				if (boolean != 0)
					if (Linie[i + 1]->Get_Name() == Zombie->Get_Name() && Linie[i]->Get_Name() == Ground->Get_Name() && Linie[i + 1]->Get_Speed() > 1) {
						Linie[i] = Linie[i + 1];
						Linie[i + 1] = Ground;
					}
			}
		}

};

