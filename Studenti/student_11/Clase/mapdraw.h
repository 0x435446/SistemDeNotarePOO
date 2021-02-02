#pragma once
#include<iostream>
#include<Windows.h>
class mapdraw
{
private:
	static mapdraw* instance;
	mapdraw();
	int p;
public:
	~mapdraw();
	void scoreboardCreate(int x, int y);
	void suncaseCreate(int x, int y);
	void homeCreate(int x, int y);
	void laneCreate(int x, int y);
	void plantbuyzone(int x, int y);
	static mapdraw* getInstance();

	
};
