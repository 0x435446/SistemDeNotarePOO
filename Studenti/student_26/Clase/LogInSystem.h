#pragma once
#include "Credentials.h"
#include "Log.h"
//Singleton
class LogInSystem
{
private:
	std::experimental::filesystem::path PathSalvari;
	void verifyPath(); //verifica daca Folderul PvZ_Users exista in C, daca nu il creeaza
	std::list<std::string> UsersList;
	void readUsers();
	bool verifyUser(); //verifica daca Userul deja exista
	void createUserFolder(); //daca user-ul nu exista se creeaza folder pt el
	void createPasswordFile(); //daca user-ul nu exista se creeaza fila ce va stoca parola
	bool verifyPassword();
	Credentials User;
	Log& History = Log::GetInstance();
	int Level = 1;
	int Score;
	//Singleton 
	static LogInSystem* Instance;
	LogInSystem(const Credentials&);
	LogInSystem(const LogInSystem&);
	~LogInSystem();
public:
	//Constructor
	static LogInSystem& GetInstance(const Credentials&);
	//Destructor
	void destroyInstance();
	//Get
	Credentials getUser()const;
	int getLevel()const;
	int getScore()const;
	//Set
	void setUser(const Credentials& User);
	void setLevel(const int& Level);
	void setScore(const int& Score);
	//Actualizeaza Level si Scor
	void updateGame();

};

