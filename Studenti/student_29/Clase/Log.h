#pragma once
#include <iostream>
#include <fstream>

namespace UserInterface
{
	class Log
	{
		static Log* instance;
	public:
		Log();
		static Log& getLogger();
		void write(const std::string&);
		void deleteLogger();
		~Log();
	};
}
