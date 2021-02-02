#pragma once
class DoubleClick
{
public:
	static void setCoords(int X, int Y);
	static void setNrClicks(int numar);
	static void getCoords1(int& X, int& Y);
	static void getCoords2(int& X, int& Y);
	static int getNrClicks();
	static DoubleClick& getInstance();
private:
	static DoubleClick* instance;
	static int coords1[2], coords2[2];
	static int nrClicks;
};