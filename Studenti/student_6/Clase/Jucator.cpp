#define _CRT_SECURE_NO_WARNINGS
#include "Jucator.h"



Jucator::Jucator(const char* nume, const char* parola)
{
	strcpy(this->nume, nume);
	strcpy(this->parola, parola);
}

void Jucator::salveaza_datele()
{
	FILE *f = fopen("info.txt", "w");
	fprintf(f, "%s", nume);
	fprintf(f, " - %s - ", parola);
}

void Jucator::salveaza_scor(int scor)
{
	FILE *f = fopen("info.txt", "a");
	fprintf(f, "%d", scor);
}

Jucator::~Jucator()
{
}
