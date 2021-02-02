#pragma once
#include <exception>
class ErrorSuns : public std::exception
{
public:
	ErrorSuns();
	~ErrorSuns();
};

