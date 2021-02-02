#include "ManagerJoc.h"
#include <iostream>
#include "Jucator.h"
#include <string>
#include <fstream>
#include "ConsoleOutput.h"
#include "Soare.h"
#include <Windows.h>
#include "ConsoleInput.h"
#include <time.h>
#include "Peashooter.h"
#include "Sunflower.h"
#include "Wallnut.h"
#include "Pea.h"
#include "Zombie.h"
#include "Buckethead.h"
#include "Log.h"
#include "Exceptie.h"

using namespace std;

ManagerJoc* ManagerJoc::manager = nullptr;

ManagerJoc::ManagerJoc()
{
	aparitieResurse = 50;
	aparitieZombie = 50;
	scor = 0;
	nrresurse = 100;
	plantaselectata = 0;
	nrzombie = 5;
}


ManagerJoc::~ManagerJoc()
{
}

ManagerJoc& ManagerJoc::getManager()
{
	if (manager == nullptr)
		manager = new ManagerJoc();
	return *manager;
}

void ManagerJoc::logare()
{
	string nume, parola;
	int nivel = 1;
	cout << "nume: ";
	cin >> nume;
	cout << "\nparola: ";
	cin >> parola;

	ifstream f("jucatori.txt");

	if (!f.is_open())
		throw Exceptie("Eroare fisier jucatori.txt");

	string numef, parolaf;
	int nivelf;

	bool gasit = false;

	while (f >> numef >> parolaf >> nivelf)
	{
		if (numef == nume)
		{
			gasit = true;
			if (parolaf == parola)
			{
				Log::logare("Autentificare reusita.");
				jucator = new Jucator(nume, parola, nivelf);
				break;
			}
			else
			{
				Log::logare("Incercare de autentificare nereusita.");
				cout << "\nParola incorecta\n";
				system("pause");
				system("cls");
				logare();
			}
		}
	}

	f.close();

	if (gasit == false)
	{
		ofstream f("jucatori.txt", ios_base::app);

		if (!f.is_open())
			throw Exceptie("Eroare fisier jucatori.txt");

		f << nume << " " << parola << " " << nivel << "\n";
		f.close();

		Log::logare("Autentificare reusita.");

		jucator = new Jucator(nume, parola, nivel);
	}
}

void ManagerJoc::joaca()
{
	Log::logare("Inceperea unui nou nivel.");
	afiseazaNivel(jucator->nivel);
	afiseazaInfo();

	while (true)
	{
		Sleep(100);
		verificaClic();
		generareResurse();
		generareZombie();
		impusca();
		lovesteZombie();
		manancaPlante();
		verificarefinal();
	}
	system("pause");
}

void ManagerJoc::afiseazaNivel(int n)
{
	system("cls");
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();

	cout << "-----     ---------------------------------------------\n";
	cout << "|---|     |   ||   ||   ||   ||   ||   ||   ||   ||   |\n";
	cout << "-----     ---------------------------------------------\n";
	cout << "\n";

	for (int i = 0; i < 9; i++)
		casuteResurse.push_back(new Casuta(1, 12 + i * 5));
	if (n >= 3)
	{
		for (int i = 1; i <= 5; i++)
		{
			cout << "-----     ---------------------------------------------\n";
			cout << "|   |     |   ||   ||   ||   ||   ||   ||   ||   ||   |\n";
			cout << "-----     ---------------------------------------------\n";
			for (int j = 0; j < 9; j++)
				casuteTeren.push_back(new Casuta(5 + (i - 1) * 3, 12 + j * 5));
		}
	}
	else if (n == 2)
	{
		cout << "-----\n";
		cout << "|   |\n";
		cout << "-----\n";

		for (int i = 1; i <= 3; i++)
		{
			cout << "-----     ---------------------------------------------\n";
			cout << "|   |     |   ||   ||   ||   ||   ||   ||   ||   ||   |\n";
			cout << "-----     ---------------------------------------------\n";

			for (int j = 0; j < 9; j++)
				casuteTeren.push_back(new Casuta(8 + (i - 1) * 3, 12 + j * 5));
		}

		cout << "-----\n";
		cout << "|   |\n";
		cout << "-----\n";
	}
	else
	{
		cout << "-----\n";
		cout << "|   |\n";
		cout << "-----\n";
		cout << "-----\n";
		cout << "|   |\n";
		cout << "-----\n";
		cout << "-----     ---------------------------------------------\n";
		cout << "|   |     |   ||   ||   ||   ||   ||   ||   ||   ||   |\n";
		cout << "-----     ---------------------------------------------\n";
		cout << "-----\n";
		cout << "|   |\n";
		cout << "-----\n";
		cout << "-----\n";
		cout << "|   |\n";
		cout << "-----\n";

		for (int j = 0; j < 9; j++)
			casuteTeren.push_back(new Casuta(11, 12 + j * 5));
	}

	UserInterface::ConsoleOutput::getInstance()(5, 2) << "P";
	UserInterface::ConsoleOutput::getInstance()(8, 2) << "Y";
	UserInterface::ConsoleOutput::getInstance()(11, 2) << "D";
	UserInterface::ConsoleOutput::getInstance()(14, 2) << "R";
	UserInterface::ConsoleOutput::getInstance()(17, 2) << "d";
	UserInterface::ConsoleOutput::getInstance()(25, 2) << "P - peashooter";
	UserInterface::ConsoleOutput::getInstance()(26, 2) << "Y - sunflower";
	UserInterface::ConsoleOutput::getInstance()(27, 2) << "D - wallnut";
	UserInterface::ConsoleOutput::getInstance()(28, 2) << "R - snowpea";
	UserInterface::ConsoleOutput::getInstance()(29, 2) << "d - cherry bomb";
	UserInterface::ConsoleOutput::getInstance()(30, 2) << "Z - zombie";
	UserInterface::ConsoleOutput::getInstance()(31, 2) << "B - buckethead";
	UserInterface::ConsoleOutput::getInstance()(32, 2) << "V - polevaulting";
	UserInterface::ConsoleOutput::getInstance()(33, 2) << "S - super zombie";
	UserInterface::ConsoleOutput::getInstance()(34, 2) << "* - pea";
}

void ManagerJoc::generareResurse()
{
	static int nrbucle = 0;

	if (nrbucle == aparitieResurse)
	{
		nrbucle = 0;
		if (resurse.size() == 9)
			return;
		srand(time(NULL));
		int inceput = rand() % 9;
		for (int k = 0; k < 9; k++)
		{
			int i = inceput + k;
			if (i >= 9)
				i -= 9;
			bool ocupat = false;
			for (int j = 0; j < resurse.size(); j++)
			{
				if (resurse[j]->getCasuta() == casuteResurse[i])
					ocupat = true;
			}
			if (!ocupat)
			{
				Soare* soare = new Soare(casuteResurse[i]);
				Log::logare("A aparut un nou soare.");
				resurse.push_back(soare);
				soare->afiseaza();
				break;
			}
		}
	}
	else
		nrbucle++;
}

void ManagerJoc::generareZombie()
{
	static int nrbucle = 0;

	if (nrbucle == aparitieZombie)
	{
		nrbucle = 0;
		if (nrzombie == 0)
			return;
		srand(time(NULL));
		int randuri = 1;
		if (jucator->nivel == 2)
			randuri = 3;
		else
			randuri = 5;
		int row = rand() % randuri + 1;
		row = 5 + (row - 1) * 3;
		Zombie* z = nullptr;
		for (auto casuta : casuteTeren)
		{
			if (casuta->r == row && casuta->c == 52)
			{
				int alegere = rand() % 2 + 1;
				if (alegere == 1)
				{
					z = new Zombie(casuta);
					Log::logare("A aparut un nou zombie.");
				}
				else
				{
					z = new Buckethead(casuta);
					Log::logare("A aparut un nou buckethead.");
				}
				z->afiseaza();
				nrzombie--;
			}
		}
		if (z != nullptr)
			zombie.push_back(z);
	}
	else
		nrbucle++;
}

void ManagerJoc::verificaClic()
{
	string s = UserInterface::ConsoleInput::getInstance().getUserActions();

	if (s != "")
	{
		UserInterface::ConsoleOutput::getInstance()(30, 70) << s;
	}
	else
		return;

	string row, col;
	int i;
	for (i = 0; i < s.size(); i++)
		if (s[i] == '/')
			break;
		else
			row.push_back(s[i]);
	for (int j = i + 1; j < s.size(); j++)
		col.push_back(s[j]);

	int r = stoi(col);
	int c = stoi(row);

	Resursa* sters = nullptr;

	for (auto resursa : resurse)
	{
		auto casuta = resursa->getCasuta();
		if (casuta->c == c || casuta->c == c + 1 || casuta->c == c - 1)
			if (casuta->r == r || casuta->r == r + 1 || casuta->r == r - 1)
			{
				nrresurse += resursa->getPuncte();
				UserInterface::ConsoleOutput::getInstance()(casuta->r, casuta->c) << ' ';
				sters = resursa;
				afiseazaInfo();
				Log::logare("Un soare a fost colectat.");
				break;
			}
	}

	if (sters != nullptr)
	{
		resurse.erase(find(resurse.begin(), resurse.end(), sters));
		delete sters;
	}

	if (c <= 3)
	{
		if (r == 4 || r == 5 || r == 6)
			if (nrresurse >= Peashooter::cost)
			{
				plantaselectata = 1;
				afiseazaInfo();
			}
		if (r == 7 || r == 8 || r == 9)
		{
			if (nrresurse >= Sunflower::cost)
			{
				plantaselectata = 2;
				afiseazaInfo();
			}
		}
		if (r == 10 || r == 11 || r == 12)
		{
			if (nrresurse >= Wallnut::cost)
			{
				plantaselectata = 3;
				afiseazaInfo();
			}
		}
	}

	Planta* p = nullptr;

	for (auto casuta : casuteTeren)
	{
		if (casuta->c == c || casuta->c == c + 1 || casuta->c == c - 1)
			if (casuta->r == r || casuta->r == r + 1 || casuta->r == r - 1)
			{
				bool ocupata = false;
				for (auto planta : plante)
					if (planta->getCasuta() == casuta)
						ocupata = true;
				if (ocupata)
					break;
				if (plantaselectata != 0)
				{
					if (plantaselectata == 1)
					{
						p = new Peashooter(casuta);
						p->afiseaza();
						nrresurse -= Peashooter::cost;
						plantaselectata = 0;
						afiseazaInfo();
					}
					if (plantaselectata == 2)
					{
						p = new Sunflower(casuta);
						p->afiseaza();
						nrresurse -= Sunflower::cost;
						plantaselectata = 0;
						afiseazaInfo();
						aparitieResurse -= 10;
					}
					if (plantaselectata == 3)
					{
						p = new Wallnut(casuta);
						p->afiseaza();
						nrresurse -= Wallnut::cost;
						plantaselectata = 0;
						afiseazaInfo();
						aparitieResurse -= 10;
					}
				}
				break;
			}
	}

	if (p != nullptr)
	{
		Log::logare("O planta a fost plantata.");
		plante.push_back(p);
	}
}

void ManagerJoc::afiseazaInfo()
{
	UserInterface::ConsoleOutput::getInstance()(2, 75) << "scor: " << scor << "        ";
	UserInterface::ConsoleOutput::getInstance()(3, 75) << "resurse: " << nrresurse << "        ";
	UserInterface::ConsoleOutput::getInstance()(1, 75) << "Nivel " << jucator->nivel << "        ";
	if (plantaselectata == 0)
		UserInterface::ConsoleOutput::getInstance()(4, 75) << "Selectata: " << "-            ";
	else if (plantaselectata == 1)
		UserInterface::ConsoleOutput::getInstance()(4, 75) << "Selectata: " << "Peashooter   ";
	else if (plantaselectata == 2)
		UserInterface::ConsoleOutput::getInstance()(4, 75) << "Selectata: " << "Sunflower   ";
}

void ManagerJoc::impusca()
{
	for (auto planta : plante)
	{
		Proiectil* p = planta->impusca();
		if (p != nullptr)
		{
			Log::logare("Un peashooter a impuscat un nou pea.");

			proiectile.push_back(p);
			p->afiseaza();
		}
	}
}

void ManagerJoc::lovesteZombie()
{
	Proiectil* p = nullptr;
	for (auto proiectil : proiectile)
	{
		Zombie* z = nullptr;
		for (auto zomb : zombie)
		{
			if (zomb->getCasuta()->r == proiectil->getCasuta()->r)
			{
				int dist = (zomb->getCasuta()->c - proiectil->getCasuta()->c);
				if (dist > 0)
				{
					int damage = proiectil->loveste(dist);
					zomb->scadehp(damage);
					if (damage > 0)
					{
						Log::logare("Un zombie a fost impuscat de un pea.");

						p = proiectil;
					}
					if (zomb->gethp() == 0)
					{
						z = zomb;
						Log::logare("Un zombie a fost eliminat.");
					}
				}
			}
		}
		if (z != nullptr)
		{
			auto it = find(zombie.begin(), zombie.end(), z);
			if (it == zombie.end())
				throw Exceptie("Eroare la stergere din vectorul zombie.");
			zombie.erase(it);
			UserInterface::ConsoleOutput::getInstance()(z->getCasuta()->r, z->getCasuta()->c) << " ";
			this->scor += 10;
			afiseazaInfo();
		}
	}
	if (p != nullptr)
	{
		auto it = find(proiectile.begin(), proiectile.end(), p);

		if (it == proiectile.end())
			throw Exceptie("Eroare la stergere din vectorul proiectile.");

		proiectile.erase(it);
	}
}

void ManagerJoc::manancaPlante()
{
	Planta* pl = nullptr;

	for (auto z : zombie)
	{
		for (auto p : plante)
		{
			if (p->getCasuta()->r == z->getCasuta()->r)
			{
				int dist = (z->getCasuta()->c - p->getCasuta()->c);
				if (dist > 0)
				{
					int damage = z->loveste(dist);
					p->scadehp(damage);
					Log::logare("O planta a fost atacata de un zombie.");
					if (p->gethp() == 0)
					{
						Log::logare("O planta a fost eliminata de un zombie");
						pl = p;
					}
					break;
				}
			}
		}
	}

	if (pl)
	{
		UserInterface::ConsoleOutput::getInstance()(pl->getCasuta()->r, pl->getCasuta()->c) << " ";
		plante.erase(find(plante.begin(), plante.end(), pl));

		delete pl;
	}
}

void ManagerJoc::verificarefinal()
{
	for (auto z : zombie)
		if (z->ajunsLaCasa((z->getCasuta()->c - 15) * 20))
		{
			Log::logare("Un zombie a ajuns la casa si jocul s-a incheiat.");
			system("CLS");
			cout << "game over" << endl;
			system("pause");
			exit(1);
		}
}