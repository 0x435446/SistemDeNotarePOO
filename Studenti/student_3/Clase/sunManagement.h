#pragma once
#include "sun.h"
#include "ConsoleOutput.h"
#include <stdlib.h>
#include <time.h>

class sunManagement
{
	static sunManagement* instance;
	int sunVector[8];
	sunManagement() {};
	sunManagement(const sunManagement &);

public:

	static sunManagement &getInstance();
	int getVector(int i) { return sunVector[i]; }
	void setVector(int i) { sunVector[i] = 0; }
	~sunManagement() {};
	void addSun();
	void deleteSun(int);
};

