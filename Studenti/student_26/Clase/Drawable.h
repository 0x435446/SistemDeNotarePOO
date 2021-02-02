#pragma once
#include "IDrawable.h"
enum OtherSign
{
	WALL = '#',
	SPACE = '.',
	UNUSABLETERRAIN = '0',
	SUNRESOURCE = 'x',
	PEASHOT = '*',
	FROZENPEASHOT = 'q'
};
enum PlantaSign {
	SUNFLOWER = L's',
	PEASHOOTER = L'p',
	CHERRYBOMB = L'c',
	WALLNUT = L'w',
	SNOWPEASHOOTER = L'n'
};
enum ZombieSign {
	REGULARZOMBIE = 'z',
	BUCKETHEAD = 'b',
	POLEVAULTING = 'v',
	SUPERZOMBIE = 'k'
};

class Drawable :
	public IDrawable
{
protected:
	//Variabile
	wchar_t cSign;
	COORD CenterOfDrawing;

	//Constructor
	Drawable(wchar_t cSign, COORD Center) :cSign(cSign), CenterOfDrawing(Center) {}
	//Overrided Functions
	virtual bool Draw(Panel&) = 0;
	virtual bool Erase(Panel&) = 0;
public:
	//Get
	const COORD& getCenterOfDrawing() const { return this->CenterOfDrawing; }
	const wchar_t& getSign() const { return this->cSign; }
	//Set
	void setSign(const wchar_t& c) { this->cSign = c; }
	void setCenterOfDrawing(COORD Center) { this->CenterOfDrawing = Center; }
};

