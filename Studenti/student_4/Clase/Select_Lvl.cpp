




//Asta a aparut singura  ???????????????????????????????????
//#include "..\..\..\..\Dispatch_2\Dispatch_2\Select_Lvl.h"        
#include "Select_Lvl.h"

void Select_Lvl::Start_Lvl()
{
	L1.Set_index(7);
	L2.Set_index(12);
	L3.Set_index(17);
	L4.Set_index(22);
	L5.Set_index(27);
}

void Select_Lvl::Level_Easy()
{
	L3.Start();
	L3.Start_Plants();
	L3.Start_Zm();
	L3.Plante_Stanga();
	Sori S1;
	S1.Start_Sori();
	S1.Set_Sun();
	int Ok = 0;
	while (L3.Lose()==0)
	{
		Map::Mapa();
		Scor::Afis_Scor();
		L3.Afisez_Fain(0);
		L3.Clear();
		S1.Afisez_Soarele();
		string MonyMony = to_string(Buzunar::Get_Resources());
		string Bani = "Bani:";
		Consola::gotoYXMov(105, 5, Bani);
		Consola::gotoYXVerde(110, 5, MonyMony);
		Scor::Afis_Scor();
		//O incrementare simpla (o puteam inlocui cu 
		//o functie si o variabila static in locul lui "Ok"
		if (Ok % 2 == 0) {
			Buzunar::Add_Resources(25);
			L3.Moneeey();
		}
		if (Ok % 5 == 0) {
			S1.Generate_Rnadom();
		}
		Ok++;
		S1.Afisez_Soarele();
		L3.Afisez_Fain(0);
		Map::Mapa();
		//Aici am apelat functia pentru citire de la tastatura
		//pentru a aduna soarele 
		int Poz;
		cin >> Poz;
		S1.Click_Pe_Soare(Poz);
		Map::Mapa();
		//Pana aici
		//Afisez iar soarele pentru ca a avut loc o schimbare
		S1.Afisez_Soarele();
		//Afisez soldul
		Consola::gotoYXMov(105, 5, Bani);
		Consola::gotoYXVerde(110, 5, MonyMony);
		L3.ItHurts_For_Zm();
		S1.Afisez_Soarele();
		L3.Clear();
		Scor::Afis_Scor();
		L3.Afisez_Fain(0);
		L3.ItHurts_For_Plants();
		L3.Clear();
		L3.Afisez_Fain(0);
		L3.Deplasez();
		L3.Afisez_Fain(0);
		int Choose;
		int Indexare;
		if (Ok % 5 == 0) {
			L3.Add_Zm();
			L3.Afisez_Fain(0);
		}
		cin >> Choose >> Indexare;
		L3.Add_Final(Choose, Indexare);
		if (L3.Lose() == 1 ) {
			Score_board::Add_Your_Score(this->Name, Scor::Get_Scor());
		}
	}
}

void Select_Lvl::Level_Medium()
{
	// Asemenea codului descris anterior, unde am L3 voi mai adauga L2 si L4
	L3.Start();
	L2.Start();
	L4.Start();
	L3.Start_Plants();
	L2.Start_Plants();
	L4.Start_Plants();
	L3.Start_Zm();
	L2.Start_Zm();
	L4.Start_Zm();
	L3.Plante_Stanga();
	Sori S1;
	S1.Start_Sori();
	S1.Set_Sun();
	int Ok = 0;
	while (L3.Lose() == 0 && L2.Lose() == 0 && L4.Lose() == 0) {
		Map::Mapa();
		Scor::Afis_Scor();
		L3.Afisez_Fain(0);
		L2.Afisez_Fain(0);
		L4.Afisez_Fain(0);
		/*L3.Clear();
		L2.Clear();
		L4.Clear();*/
		S1.Afisez_Soarele();
		string MonyMony = to_string(Buzunar::Get_Resources());
		string Bani = "Bani:";
		Consola::gotoYXMov(105, 5, Bani);
		Consola::gotoYXVerde(110, 5, MonyMony);
		Scor::Afis_Scor();
		if (Ok % 2 == 0) {
			Buzunar::Add_Resources(25);
			L3.Moneeey();
			L2.Moneeey();
			L4.Moneeey();
		}
		if (Ok % 5 == 0) {
			S1.Generate_Rnadom();
		}
		Ok++;
		S1.Afisez_Soarele();
		L3.Afisez_Fain(0);
		L2.Afisez_Fain(0);
		L4.Afisez_Fain(0);
		Map::Mapa();
		//Aici am apelat functia pentru citire de la tastatura
		//pentru a aduna soarele 
		int Poz;
		cin >> Poz;
		S1.Click_Pe_Soare(Poz);
		Map::Mapa();
		//
		//Pana aici
		//Afisez iar soarele pentru ca a avut loc o schimbare
		S1.Afisez_Soarele();
		//Afisez soldul
		Consola::gotoYXMov(105, 5, Bani);
		Consola::gotoYXVerde(110, 5, MonyMony);
		L3.ItHurts_For_Zm();
		L2.ItHurts_For_Zm();
		L4.ItHurts_For_Zm();
		S1.Afisez_Soarele();
		L3.Clear();
		L2.Clear();
		L4.Clear();
		Scor::Afis_Scor();
		L3.Afisez_Fain(0);
		L2.Afisez_Fain(0);
		L4.Afisez_Fain(0);
		L3.ItHurts_For_Plants();
		L2.ItHurts_For_Plants();
		L4.ItHurts_For_Plants();
		L3.Clear();
		L2.Clear();
		L4.Clear();
		L3.Afisez_Fain(0);
		L2.Afisez_Fain(0);
		L4.Afisez_Fain(0);
		L3.Deplasez();
		L2.Deplasez();
		L4.Deplasez();
		L3.Afisez_Fain(0);
		L2.Afisez_Fain(0);
		L4.Afisez_Fain(0);
		int Linia_aleasa;
		if (Ok % 5 == 0) {
			L3.Add_Zm();
			L3.Afisez_Fain(0);
		}
		if (Ok % 8 == 0) {
			L2.Add_Zm();
			L2.Afisez_Fain(0);
		}
		if (Ok % 11 == 0) {
			L4.Add_Zm();
			L4.Afisez_Fain(0);
		}
		cin >> Linia_aleasa;
		int Choose;
		int Indexare;
		cin >> Choose >> Indexare;
		if (Linia_aleasa == 2) {
			L2.Add_Final(Choose, Indexare);
		}
		if (Linia_aleasa == 3) {
			L3.Add_Final(Choose, Indexare);
		}
		if (Linia_aleasa == 4) {
			L4.Add_Final(Choose, Indexare);
		}
		if (L3.Lose() == 1 || L2.Lose() == 1 || L4.Lose() == 1 ) {
			Score_board::Add_Your_Score(this->Name, Scor::Get_Scor());
		}
	}
}
void Select_Lvl::Set_Name(string Name) {
	this->Name = Name;
}

void Select_Lvl::Level_Hard()
{
	
	L3.Start();
	L2.Start();
	L4.Start();
	L1.Start();
	L5.Start();

	L3.Start_Plants();
	L2.Start_Plants();
	L4.Start_Plants();
	L1.Start_Plants();
	L5.Start_Plants();

	L3.Start_Zm();
	L2.Start_Zm();
	L4.Start_Zm();
	L1.Start_Zm();
	L5.Start_Zm();

	L3.Plante_Stanga();

	Sori S1;
	S1.Start_Sori();
	S1.Set_Sun();
	int Ok = 0;
	while (L3.Lose() == 0 && L2.Lose() == 0 && L4.Lose() == 0 && L1.Lose()==0 && L5.Lose()==0) {
		Map::Mapa();
		Scor::Afis_Scor();
		L3.Afisez_Fain(0);
		L2.Afisez_Fain(0);
		L4.Afisez_Fain(0);
		L1.Afisez_Fain(0);
		L5.Afisez_Fain(0);
		/*L3.Clear();
		L2.Clear();
		L4.Clear();*/
		S1.Afisez_Soarele();
		string MonyMony = to_string(Buzunar::Get_Resources());
		string Bani = "Bani:";
		Consola::gotoYXMov(105, 5, Bani);
		Consola::gotoYXVerde(110, 5, MonyMony);
		Scor::Afis_Scor();
		if (Ok % 2 == 0) {
			Buzunar::Add_Resources(25);
			L3.Moneeey();
			L2.Moneeey();
			L4.Moneeey();
			L1.Moneeey();
			L5.Moneeey();
		}
		if (Ok % 5 == 0) {
			S1.Generate_Rnadom();
		}
		Ok++;
		S1.Afisez_Soarele();
		L3.Afisez_Fain(0);
		L2.Afisez_Fain(0);
		L4.Afisez_Fain(0);
		L1.Afisez_Fain(0);
		L5.Afisez_Fain(0);
		Map::Mapa();
		//Aici am apelat functia pentru citire de la tastatura
		//pentru a aduna soarele 
		int Poz;
		cin >> Poz;
		S1.Click_Pe_Soare(Poz);
		Map::Mapa();
		//
		//Pana aici
		//Afisez iar soarele pentru ca a avut loc o schimbare
		S1.Afisez_Soarele();
		//Afisez soldul
		Consola::gotoYXMov(105, 5, Bani);
		Consola::gotoYXVerde(110, 5, MonyMony);
		L3.ItHurts_For_Zm();
		L2.ItHurts_For_Zm();
		L4.ItHurts_For_Zm();
		L1.ItHurts_For_Zm();
		L5.ItHurts_For_Zm();

		S1.Afisez_Soarele();
		L3.Clear();
		L2.Clear();
		L4.Clear();
		L1.Clear();
		L5.Clear();
		Scor::Afis_Scor();
		L3.Afisez_Fain(0);
		L2.Afisez_Fain(0);
		L4.Afisez_Fain(0);
		L1.Afisez_Fain(0);
		L5.Afisez_Fain(0);

		L3.ItHurts_For_Plants();
		L2.ItHurts_For_Plants();
		L4.ItHurts_For_Plants();
		L1.ItHurts_For_Plants();
		L5.ItHurts_For_Plants();

		L3.Clear();
		L2.Clear();
		L4.Clear();
		L1.Clear();
		L5.Clear();

		L3.Afisez_Fain(0);
		L2.Afisez_Fain(0);
		L4.Afisez_Fain(0);
		L1.Afisez_Fain(0);
		L5.Afisez_Fain(0);

		L3.Deplasez();
		L2.Deplasez();
		L4.Deplasez();
		L1.Deplasez();
		L5.Deplasez();

		L3.Afisez_Fain(0);
		L2.Afisez_Fain(0);
		L4.Afisez_Fain(0);
		L1.Afisez_Fain(0);
		L5.Afisez_Fain(0);

		if (Ok % 5 == 0) {
			L3.Add_Zm();
			L3.Afisez_Fain(0);
		}
		if (Ok % 8 == 0) {
			L2.Add_Zm();
			L2.Afisez_Fain(0);
		}
		if (Ok % 11 == 0) {
			L4.Add_Zm();
			L4.Afisez_Fain(0);
		}

		if (Ok % 14 == 0) {
			L1.Add_Zm();
			L1.Afisez_Fain(0);
		}

		if (Ok % 17 == 0) {
			L5.Add_Zm();
			L5.Afisez_Fain(0);
		}
		int Linia_aleasa;
		cin >> Linia_aleasa;
		int Choose;
		int Indexare;
		cin >> Choose >> Indexare;
		if (Linia_aleasa == 2) {
			L2.Add_Final(Choose, Indexare);
		}
		if (Linia_aleasa == 3) {
			L3.Add_Final(Choose, Indexare);
		}
		if (Linia_aleasa == 4) {
			L4.Add_Final(Choose, Indexare);
		}
		if (Linia_aleasa == 1) {
			L1.Add_Final(Choose, Indexare);
		}
		if (Linia_aleasa == 5) {
			L1.Add_Final(Choose, Indexare);
		}
		if (L3.Lose() == 1 || L2.Lose() == 1 || L4.Lose() == 1 || L1.Lose() == 1 || L5.Lose() == 1) {
			Score_board::Add_Your_Score(this->Name, Scor::Get_Scor());
		}
	}
}

void Select_Lvl::Choose(int x)
{
	if (x == 1)
		this->Level_Easy();
	if (x == 2)
		this->Level_Medium();
	if (x == 3)
		this->Level_Hard();
}


//void Select_Lvl::Level_Medium() {
//	//Asemenea codului descris anterior,unde am L3 voi mai adauga L2 si L4
//	L3.Start_Plants();
//	L2.Start_Plants();
//	L4.Start_Plants();
//	L3.Start_Zm();
//	L2.Start_Zm();
//	L4.Start_Zm();
//	Sori S1;
//	S1.Start_Sori();
//	S1.Set_Sun();
//	int Ok = 0;
//	while (L3.Lose() == 0 && L2.Lose() == 0 && L4.Lose() == 0) {
//		Map::Mapa();
//		Scor::Afis_Scor();
//		L3.Afisez_Fain(0);
//		L2.Afisez_Fain(0);
//		L4.Afisez_Fain(0);
//		L3.Clear();
//		L2.Clear();
//		L4.Clear();
//		S1.Afisez_Soarele();
//		string MonyMony = to_string(Buzunar::Get_Resources());
//		string Bani = "Bani:";
//		Consola::gotoYXMov(105, 5, Bani);
//		Consola::gotoYXVerde(110, 5, MonyMony);
//		Scor::Afis_Scor();
//		if (Ok % 2 == 0) {
//			Buzunar::Add_Resources(25);
//			L3.Moneeey();
//			L2.Moneeey();
//			L4.Moneeey();
//		}
//		if (Ok % 5 == 0) {
//			S1.Generate_Rnadom();
//		}
//		Ok++;
//		S1.Afisez_Soarele();
//		L3.Afisez_Fain(0);
//		L2.Afisez_Fain(0);
//		L4.Afisez_Fain(0);
//		Map::Mapa();
//		//Aici am apelat functia pentru citire de la tastatura
//		//pentru a aduna soarele 
//		int Poz;
//		cin >> Poz;
//		S1.Click_Pe_Soare(Poz);
//		Map::Mapa();
//		//
//		//Pana aici
//		//Afisez iar soarele pentru ca a avut loc o schimbare
//		S1.Afisez_Soarele();
//		//Afisez soldul
//		Consola::gotoYXMov(105, 5, Bani);
//		Consola::gotoYXVerde(110, 5, MonyMony);
//		L3.ItHurts_For_Zm();
//		L2.ItHurts_For_Zm();
//		L4.ItHurts_For_Zm();
//		S1.Afisez_Soarele();
//		L3.Clear();
//		L2.Clear();
//		L4.Clear();
//		Scor::Afis_Scor();
//		L3.Afisez_Fain(0);
//		L2.Afisez_Fain(0);
//		L4.Afisez_Fain(0);
//		L3.ItHurts_For_Plants();
//		L2.ItHurts_For_Plants();
//		L4.ItHurts_For_Plants();
//		L3.Clear();
//		L2.Clear();
//		L4.Clear();
//		L3.Afisez_Fain(0);
//		L2.Afisez_Fain(0);
//		L4.Afisez_Fain(0);
//		L3.Deplasez();
//		L2.Deplasez();
//		L4.Deplasez();
//		L3.Afisez_Fain(0);
//		L2.Afisez_Fain(0);
//		L4.Afisez_Fain(0);
//		int Linia_aleasa;
//		cin >> Linia_aleasa;
//		int Choose;
//		int Indexare;
//		cin >> Choose >> Indexare;
//		if (Linia_aleasa == 2) {
//			L2.Add_Final(Choose, Indexare);
//		}
//		if (Linia_aleasa == 3) {
//			L3.Add_Final(Choose, Indexare);
//		}
//		if (Linia_aleasa == 4) {
//			L4.Add_Final(Choose, Indexare);
//		}
//	}
//}