#include "Exception.h"

using namespace Debugging;

std::vector<std::string> exceptionStrings = { "File error", "Out of bounds", "Spawn error" };

Exception::Exception(std::string func, std::string file, int line, ExceptionTypes type)
{
	message = exceptionStrings[type];
	message += " - error encountered in function <<";
	message += func;
	message += ">> (";
	message += file;
	message += ", line ";
	message += std::to_string(line);
	message+=") ";

	Debugging::Logger::getInstance().log(message);
}

Exception::Exception(std::string info, std::string func, std::string file, int line, ExceptionTypes type)
{
	Exception(func, file, line, type);
	message += "-> ";
	message += info;
}


Exception::~Exception()
{
}

std::string Debugging::Exception::getMessage()
{
	return message;
}
