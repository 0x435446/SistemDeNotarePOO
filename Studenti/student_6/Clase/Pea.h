#pragma once
#include"Proiectile.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Coordonate.h"
#include <time.h>
#include <chrono>

using namespace std::chrono;

class Pea:public Proiectile
{
public:
	Pea(int);
	~Pea();

	void ataca(int,int)override;
};

