#pragma once
#include "IShot.h"
#include "Drawable.h"
#include <chrono>
#include <time.h>

class Shot :
	public IShot,
	public Drawable
{
public:
	//Override
	virtual void Move(Panel&) override = 0;
	virtual void destroy()
	{
		nFrameCount = 0;
		this->setCenterOfDrawing(PozitieInitiala);
		nOffsetShot = 0;
	}
	//Get
	const int& getShotMVS() { return this->ProjectileMovementSpeed; }
	auto getStart() { return this->Start; }
	//Set
	void setShotMVS(int Val) { this->ProjectileMovementSpeed = Val; }
	void setStart(std::chrono::time_point<std::chrono::steady_clock>val) { this->Start = val; }
	//Behavior
	virtual bool Draw(Panel&) = 0;
	virtual bool Erase(Panel&) = 0;
protected:
	int ProjectileMovementSpeed;
	const COORD PozitieInitiala;
	int nFrameCount = 0;
	int nOffsetShot = 0; //Distanta fata de punctul initial
	std::chrono::time_point<std::chrono::steady_clock> Start = std::chrono::high_resolution_clock::now(); //De cand exista Shot ul
	
	//Constructor
	Shot(wchar_t cSign, COORD Center) :Drawable(cSign, Center), ProjectileMovementSpeed(100),PozitieInitiala(Center) {}
};

