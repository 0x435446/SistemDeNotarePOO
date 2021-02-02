#pragma once
#include <Windows.h>
class sun
{
	char type = 'S';
	int value = 25;
	COORD pos;

public:

	void gotoxy(int x, int y);
	sun();
	void setcord(short x, short y);
	COORD getcord();
	int getValue();
	void setValue(int newVAL);
	void afiseaza(COORD pos);
	void sterge(COORD pos);
	void aprox_coord(short& x, short& y);
};
