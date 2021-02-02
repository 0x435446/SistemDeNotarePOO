#pragma once
#include<iostream>
#include<string>

class Jucator
{
private:
	char nume[100];
	char parola[100];
public:
	Jucator(const char*,const char*);
	~Jucator();

	void salveaza_datele();
	void salveaza_scor(int scor);
};

