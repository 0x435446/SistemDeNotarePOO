#include "Log.h"
namespace fs = std::experimental::filesystem;
Log* Log::Instance = nullptr;

Log::Log()
{
}

Log::Log(const Log&)
{
}

Log::~Log()
{
}

Log& Log::GetInstance()
{
	if (Instance == nullptr)
		Instance = new Log;
	return *Instance;
}

void Log::destroyInstance()
{
	if (Instance == nullptr)
		return;
	delete Instance;
	Instance = nullptr;
}

std::experimental::filesystem::path Log::getPathFiles() const
{
	return this->PathFiles;
}

void Log::setPathFiles(std::experimental::filesystem::path& path)
{
	this->PathFiles = path;
}

void Log::addInLog(const int& Level, const int& Score)
{
	std::ofstream File;
	fs::path path = Instance->getPathFiles();
	path.append("Log.log");

	File.open(path);
	if (File.is_open())
	{
		File << Level;
		File << std::endl;
		File << Score;
	}
	File.close();
}

void Log::readLog(int* Level, int* Score)
{
	std::ifstream File;
	std::string buffer;
	fs::path path = Instance->getPathFiles();
	path.append("Log.log");

	File.open(path);
	if (File.is_open())
	{
		if (std::getline(File, buffer))
		{
			*Level = stoi(buffer); //prima linie in log e level ul
			if (std::getline(File, buffer))//a doua linie e score ul
			{
				*Score = stoi(buffer);
			}
		}
	}
	else //daca nu reuseste sa deschida log-ul inseamna ca e un player nou
	{
		*Level = 1;
		*Score = 0;
	}
	File.close();
}