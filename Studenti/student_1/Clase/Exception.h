#pragma once
#include <string>
#include <vector>

#include "Logger.h"

namespace Debugging
{
	enum ExceptionTypes { FILE_ERROR, OUT_OF_BOUNDS, SPAWN_ERROR };

	class Exception
	{
	private:
		std::string message;

	public:
		Exception(std::string func, std::string file, int line, ExceptionTypes type);
		Exception(std::string info, std::string func, std::string file, int line, ExceptionTypes type);
		~Exception();

		std::string getMessage();
	};
}
