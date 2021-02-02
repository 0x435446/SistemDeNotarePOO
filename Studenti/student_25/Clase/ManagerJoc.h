#pragma once

#include <vector>

using namespace std;

class Jucator;
class Casuta;
class Resursa;
class Planta;
class Zombie;
class Proiectil;

class ManagerJoc
{
private:
	ManagerJoc();
	~ManagerJoc();

	static ManagerJoc* manager;

	Jucator* jucator;
	vector<Casuta*> casuteResurse;
	vector<Casuta*> casuteTeren;
	vector<Resursa*> resurse;
	vector<Planta*> plante;
	vector<Zombie*> zombie;
	vector<Proiectil*> proiectile;

	int aparitieResurse;
	int aparitieZombie;
	int scor;
	int nrresurse;
	int plantaselectata;
	int nrzombie;

	void afiseazaNivel(int n);
	void generareResurse();
	void generareZombie();
	void verificaClic();
	void afiseazaInfo();
	void impusca();
	void lovesteZombie();
	void manancaPlante();
	void verificarefinal();

public:

	static ManagerJoc& getManager();

	void logare();
	void joaca();
};


