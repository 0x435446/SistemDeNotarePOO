#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Players
{
public:
	static Players& getInstance();
	static void destroyInstance();

	static int checkPlayer();
	static void addPlayer();
	static string getName();
	static string getPassword();
	static void setName(string nume);
	static void setPassword(string parola);
	static void setScore(int scor);
	static int getScore();

private:
	static Players* instance;
	static std::string name;
	static std::string password;
	static int score;
	Players();

};

