#include "Resurse_Sun.h"


void Resurse_Sun::Add_Sun( )
{
	this->Sun += 25;
}

void Resurse_Sun::Sub_Sun(int Valoare)
{
	this->Sun -= Valoare;
}

void Resurse_Sun::Add_Time(int Valoare)
{
	this->ReduceTime += Valoare;
}

void Resurse_Sun::Sub_Time(int Valoare)
{
	this->ReduceTime -= Valoare;
}

float Resurse_Sun::GetTime()
{
	return (float)(this->SpawnTime - this->ReduceTime);
}

Resurse_Sun::Resurse_Sun()
{

}

Resurse_Sun::~Resurse_Sun()
{

}
