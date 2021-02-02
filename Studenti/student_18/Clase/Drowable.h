#pragma once
#include"iDrowable.h"
class Drowable:public iDrowable
{
protected:
	unsigned row, col;
	std::string shape;
public:
	 Drowable(const unsigned&row, const unsigned&col, const std::string&shape);
	 virtual ~Drowable() {}
	 unsigned getRow() const override final{ return this->row; }
	 unsigned getCol() const override final{ return this->col; }
	 void setRow(const unsigned& row) override final{ this->row = row; }
	 void setCol(const unsigned& col) override final{ this->col = col; }
};

