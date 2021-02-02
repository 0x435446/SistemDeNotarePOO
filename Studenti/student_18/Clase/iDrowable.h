#pragma once
#include<iostream>
#include<string>
#include<time.h>
#include"ConsoleOutput.h"
#include"ConsoleInput.h"
class iDrowable
{
public:
	iDrowable() {}
	virtual ~iDrowable() {};
	virtual unsigned getRow() const = 0;
	virtual unsigned getCol() const = 0;
	virtual void setRow(const unsigned& row) = 0;
	virtual void setCol(const unsigned& col) = 0;
	virtual void printEntity()const = 0;
	virtual void clearEntity()const = 0;
};