#pragma once
#include"Panel.h"
#include<windows.h>

class IDrawable
{
protected:
	//This need to be Overrided for the specific Drawing
	virtual bool Draw(Panel&) = 0;
	virtual bool Erase(Panel&) = 0;
	//Get
	virtual const COORD& getCenterOfDrawing() const = 0;
	virtual const wchar_t& getSign() const = 0;
};

