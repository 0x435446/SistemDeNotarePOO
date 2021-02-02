#pragma once

#include<iostream>

#include<Windows.h>



class Sun
{
private:
	int numberSun;
	int sunRow;
	int sunCol;
	int sunWait;
public:
	Sun();
    ~Sun();
	void CheckForSun(std::string action);

	void CheckForSun(int xPos, int yPos);

	void ReduceTimeToWait();

	int GetSunRow();

	int GetSunCol();

	int GetSunWait();

	void SetSunRow(int row);

	void SetSunCol(int col);

	int GetNumberSun();

	void ReduceNumberSun(int number);

	void SetSun();
};

