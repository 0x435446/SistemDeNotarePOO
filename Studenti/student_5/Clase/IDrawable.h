#pragma once
#include <string>
class IDrawable
{
public:
	IDrawable();
	~IDrawable();
	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual std::string getGlyph() = 0;
	virtual void setX(int x) = 0;
	virtual void setY(int y) = 0;
	virtual void setGlyph(std::string glyph) = 0;

};

