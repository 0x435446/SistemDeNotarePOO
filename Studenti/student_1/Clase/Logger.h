#pragma once

#include <ctime>
#include <fstream>

#include "GameSpecifications.h"

namespace Debugging
{
	class Entity;
	class Logger
	{
	private:
		Logger();
		Logger(Logger&);
		~Logger();

		std::ofstream out;

		static Logger* instance;

	public:
		static Logger& getInstance();
		static void destroyInstance();

		void log(std::string);
	};

	std::ofstream& operator << (std::ofstream & os, time_t &);
}