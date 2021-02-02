#include "Exception.h"

Exception::Exception(std::string message) : message(message)
{
}

Exception::~Exception()
{
}

std::ostream& operator<<(std::ostream& out, Exception& exception)
{
	out << "Exception handled with message: " << exception.message << std::endl;
	return out;
}