#include "IDrawable.h"

using namespace UserInterface;

IDrawable::IDrawable(int rowUp, int colLeft) : rowUp(rowUp), colLeft(colLeft)
{
}


IDrawable::~IDrawable()
{
}

unsigned UserInterface::IDrawable::getRowUp()
{
	return rowUp;
}

unsigned IDrawable::getColLeft()
{
	return this->colLeft;
}

unsigned UserInterface::IDrawable::getWidth()
{
	return width;
}
