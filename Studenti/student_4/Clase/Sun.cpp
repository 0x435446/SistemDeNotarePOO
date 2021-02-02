#include "Sun.h"

Sun::Sun(int Valoare,int da_sau_nu) :Resources(Valoare)
{
	this->Da_Sau_Nu = da_sau_nu;
}

int Sun::Give_Resource()
{
	return this->Valoare;
}
