#include "DoubleClick.h"

DoubleClick* DoubleClick::instance = nullptr;
int DoubleClick::coords1[] = { 0, 0 };
int DoubleClick::nrClicks = 0;
int DoubleClick::coords2[] = { 0, 0};

void DoubleClick::setCoords(int X,int Y)
{

	nrClicks++;
	if (nrClicks % 2 == 0) {
		coords2[0] = X;
		coords2[1] = Y;
	}
	else {

		coords1[0] = X;
		coords1[1] = Y;
	}
}

void DoubleClick::setNrClicks(int numar)
{
	nrClicks = numar;
}

void DoubleClick::getCoords1(int& X, int& Y)
{
	X = coords1[0];
	Y = coords1[1];
}

void DoubleClick::getCoords2(int& X, int& Y)
{
	X = coords2[0];
	Y = coords2[1];
}
int DoubleClick::getNrClicks()
{
	return nrClicks;
}

DoubleClick& DoubleClick::getInstance()
{
	if (!DoubleClick::instance) {
		DoubleClick::instance = new DoubleClick();
	}
	return *DoubleClick::instance;
}
