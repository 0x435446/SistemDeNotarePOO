#include "Log.h"

UserInterface::Log* UserInterface::Log::instance = nullptr;

UserInterface::Log::Log()
{
	std::ofstream outfile;

	outfile.open("log.txt", std::ios_base::out);

	outfile << "Creating log file (log.txt)...\n";
	outfile << "Log file created.\n";

	outfile.close();
}

UserInterface::Log& UserInterface::Log::getLogger()
{
	if (!instance)
	{
		instance = new Log();
	}
	return (*instance);
}

void UserInterface::Log::write(const std::string& action)
{
	std::ofstream outfile;

	outfile.open("log.txt", std::ios_base::app); 

	if (outfile.is_open())
	{
		outfile << action << "\n";
		outfile.close();
	}
}

void UserInterface::Log::deleteLogger()
{
	delete instance;
	instance = nullptr;
	this->~Log();
}

UserInterface::Log::~Log()
{
}