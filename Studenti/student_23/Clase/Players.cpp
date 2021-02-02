#include "Players.h"

Players* Players::instance = nullptr;
std::string Players::name = "0";
std::string Players::password = "0";
int Players::score = 0;

Players::Players()
{

}

Players& Players::getInstance()
{
	if (!Players::instance) {
		Players::instance = new Players();
	}
	return *Players::instance;
}

void Players::destroyInstance()
{
	if (Players::instance) {
		delete Players::instance;
		Players::instance = nullptr;
	}
}

int Players::checkPlayer()
{
	string buffer;
	bool test = false;
	std::ifstream jucatori("Players.txt");
	if (jucatori.is_open()) {
		while (EOF) {
			jucatori >> buffer;
			if (buffer.compare(name) == 0) {
				test = true;
				jucatori >> buffer;
				jucatori >> buffer;
				if (buffer.compare(password) == 0)
					return 1;
				else
				{
					return 0;
				}

			}
		}
	}

	if (!test) {
		return -1;
	}
	jucatori.close();
}

void Players::addPlayer()
{

	std::ofstream adaugaJucator("Players.txt",ios::out|ios::app);
	
	adaugaJucator << name << " | " << password << " | 0\n";

	adaugaJucator.close();
}

string Players::getName()
{
	return name;
}

string Players::getPassword()
{
	return password;
}

void Players::setName(string nume)
{
	name = nume;
}

void Players::setPassword(string parola)
{
	password = parola;
}

void Players::setScore(int scor)
{
	score = scor;
}

int Players::getScore()
{
	return score;
}



