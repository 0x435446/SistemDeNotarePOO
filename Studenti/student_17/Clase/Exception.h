#pragma once
#include <iostream>

class Exception
{
public:
	Exception(std::string message);
	~Exception();

	friend std::ostream& operator<<(std::ostream& out, Exception &exception);
private:
	std::string message;
};