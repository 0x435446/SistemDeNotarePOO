#pragma once
#include<iostream>
#include<Windows.h>

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include<thread>

class GenerateSun
{
	static GenerateSun* instance;
	static int sunRow;
	static int sunCol;
public:
	GenerateSun();
	~GenerateSun();
	static GenerateSun& Get_Insance();
};

static int sunRow=0;
static int sunCol=0;