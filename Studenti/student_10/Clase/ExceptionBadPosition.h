#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ExceptionBadPosition : public exception
{
public:
	ExceptionBadPosition();
	~ExceptionBadPosition();

	virtual const char* what() const throw()
	{
		return "Invalid position of element on board";
	}
};

