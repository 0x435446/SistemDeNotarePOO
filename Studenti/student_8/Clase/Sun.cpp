#include "Sun.h"
#include <ctime>

Sun::Sun()
{
	this->x = 10; this->y = 10;
	this->valoare = 35;
	
	this->aparut = -1;
}
Sun::Sun(int i)
{
	int val = 35;

	switch (i)
	{
	case 0:
	{
		this->x = 63;
		this->y = 9;
		this->valoare = val;
		
		this->aparut = -1;
		return;
	}
	case 1:
	{
		this->x = 71;
		this->y = 9;
		this->valoare = val;
	
		this->aparut = -1;
		return;
	}
	case 2:
	{
		this->x = 79;
		this->y = 9;
		this->valoare = val;
	
		this->aparut = -1;
		return;
	}
	case 3:
	{
		this->x = 87;
		this->y = 9;
		this->valoare = val;
		
		this->aparut = -1;
		return;
	}
	case 4:
	{
		this->x = 95;
		this->y = 9;
		this->valoare = val;
		
		this->aparut = -1;
		return;
	}
	case 5:
	{
		this->x = 103;
		this->y = 9;
		this->valoare = val;
		this->aparut = -1;
		
		return;
	}
	case 6:
	{

		this->x = 111;
		this->y = 9;
		this->valoare = val;
		
		this->aparut = -1;
		return;
	}
	}
}
void Sun::write()
{
	conOut(this->x, this->y) << "O";
}
void Sun::unwrite()
{     
	this->aparut = -1;
	conOut(this->x, this->y) << " ";
}

auto timp = steady_clock::now();
void Sun::verifAfisare(Sun sun[],int interval)
{

	int k = 0, sum;

	if (duration_cast<seconds>(steady_clock::now() - timp).count() > interval)
	{
	
		timp = steady_clock::now();
		sum = 0;
		for (int i = 0; i < 7; ++i)
			sum = sum + sun[i].aparut;

		if (sum == 7)
		{
			
			conOut(75, 3) << "Stiva de sori este plina !!!";
		}
		else
			conOut(75, 3) << "                              ";
		k = rand() % 7;
		if (sun[k].aparut == -1)
		{
			sun[k].write();
			sun[k].aparut =1;
		}
		else
			for (int i = 0; i < 7; ++i)
			{
				if (sun[i].aparut == -1)
				{
					sun[i].write();
					sun[i].aparut =1;
					break;
				}
			}



	}
}
int Sun::cursor(string buff)
{
	string buff1, buff2;
	int ax = 1;
	int ay = 1;
	int sum=0;
	if (buff != "")
	{
		buff1 = buff.substr(0, 3);
		buff2 = buff.substr(3, 2);

		if (buff1 != "mou" && buff2 != "mo")
		{
			ax = stoi(buff1);
			ay = stoi(buff2);
			
		}
	}
	if (ax > 0 && ax < 1000)
	{
			if ((this->x > ax - 3 && this->x < ax + 3) && (this->aparut != -1) && (this->y > ay - 1 && this->y < ay + 1))
			{  
				unwrite();
				this->aparut =-1;
				ax = 1;
				ay = 1;
				return this->valoare;

			}

		}
	return 0;
	}




Sun::~Sun()
{

}


