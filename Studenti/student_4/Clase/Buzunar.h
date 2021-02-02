#pragma once
#include <stdlib.h>
//Aici tin minte cate unitati de tip resursa am
//Pot sa adaug si sa scad si sa returnez cat sold este in mom de fata;

class Buzunar
{
private:
	static int Sold_curent;
	static Buzunar* Instance;
	Buzunar();
public:
	static void Add_Resources(int Resurse);
	static void  Pay_Resources(int Cost);
	static int Verify(int Cost);
	static int Get_Resources();
	static Buzunar* Set_Instance()
	{
		if (Instance!=NULL)
			Instance = new Buzunar();
		return Instance;
	}
};

