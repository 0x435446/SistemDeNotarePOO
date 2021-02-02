#pragma once
#include"Drawable.h"
#include<windows.h>

class Panel;

class Sun:
	public Drawable
{
private:
	static int nResources;
	int nVal;
public:
	Sun(int Val, COORD Center) :nVal(Val),Drawable(L'x',Center){}
	~Sun() {};
	//Get
	int& getVal() { return this->nVal; }
	int& getResources() { return nResources; }
	//Set
	void setVal(int Val){ this->nVal = Val; }
	void setResources(int Val) { nResources = Val; }
	//Behavior
	virtual bool Draw(Panel& panel) override;
	virtual bool Erase(Panel& panel) override;
	//Ability

};

