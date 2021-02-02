#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include<string>
#include<fstream>
#include <iostream>
#include<experimental/filesystem>
//Singleton
 class Log
{
private:
	std::experimental::filesystem::path PathFiles;
	//Singleton
	static Log* Instance;
	Log();
	Log(const Log&);
	~Log();
public:
	//Constructor
	static Log& GetInstance();
	//Destructor
	void destroyInstance();
	//Get
	std::experimental::filesystem::path getPathFiles() const;
	//Set
	void setPathFiles(std::experimental::filesystem::path&);
	//Function
	void addInLog(const int&, const int&);
	void readLog(int*, int*);
};