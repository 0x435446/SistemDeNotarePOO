#pragma once
#include "IDrawable.h"
#include "BattleLine.h"
class Battlefield :public IDrawable
{
public:
	static Battlefield& getInstance(int);
	~Battlefield() { ; }
	int pressedInside(int, int);
	bool addPlant(int,std::string);
	bool getSuns(int, int);
	bool testLoss();
	int executeFunction();
	void draw();
private:
	static Battlefield* instance;
	steady_clock::time_point genRegular;
	steady_clock::time_point genBucket;
	steady_clock::time_point genVaulting;
	Battlefield(int);
	int difficulty;
	vector<BattleLine*> fieldLines;
};

