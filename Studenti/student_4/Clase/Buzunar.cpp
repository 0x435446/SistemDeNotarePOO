#include "Buzunar.h"

Buzunar::Buzunar()
{
	Buzunar::Sold_curent = 100;
}

void Buzunar::Add_Resources(int Resurse)
{
	Buzunar::Sold_curent = Buzunar::Sold_curent + Resurse;
}

void Buzunar::Pay_Resources(int Cost)
{
	if (Buzunar::Verify(Cost) == 1)
		Buzunar::Sold_curent = Buzunar::Sold_curent - Cost;
}

int Buzunar::Verify(int Cost)
{
	if(Buzunar::Get_Resources()<Cost)
	return 0;
	else
	{
		return 1;
	}
}

int Buzunar::Get_Resources()
{
	return Buzunar::Sold_curent;
}
int Buzunar::Sold_curent = 0;
Buzunar* Buzunar::Instance = NULL;