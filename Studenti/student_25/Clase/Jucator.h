#pragma once

#include <string>
using namespace std;

class Jucator
{
private:
	string nume;
	string parola;
	int nivel;

public:
	Jucator(string, string, int);
	~Jucator();

	friend class ManagerJoc;
};


