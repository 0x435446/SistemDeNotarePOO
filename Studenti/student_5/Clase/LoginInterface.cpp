#include "LoginInterface.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>
#define Left_x 50
#define top_y 15
#define Right_x 110
#define bottom_y 25
#define Message_x 65
#define Message_y 17


LoginInterface::LoginInterface()
{
}


LoginInterface::~LoginInterface()
{
}

void LoginInterface::start(UserInterface::ConsoleOutput conOut, std::string &user)
{
	std::ifstream logInFile("users.db");
	if (!logInFile.is_open())
		throw std::exception("Nu exista fisierul users.db, creaza unu!");

	std::string username = "";
	std::string password = "";
	bool isThere = false;
	auto cleanArena = [](UserInterface::ConsoleOutput conOut) {
		for (int y = top_y + 1; y < bottom_y; y++) {
			for (int x = Left_x + 1; x < Right_x; x++)
				conOut(x, y) << " ";
		}
	};
	auto getInputFromConsole = [&](std::string &input) {
		char inputChar = '\0';
		while (inputChar != '\r') {
			inputChar = _getch();
			if (inputChar != '\0' && inputChar != '\r') {
				std::cout << inputChar;
				input += inputChar;
			}
		}
	};
	//linia de sus
	for (int i = Left_x; i <= Right_x; i++)
		conOut(i, top_y) << "_";
	//linia de jos
	for (int i = Left_x; i <= Right_x; i++)
		conOut(i, bottom_y) << "_";
	//linia din stanga
	for (int i = top_y + 1; i <= bottom_y; i++)
		conOut(Left_x, i)<<"|";
	//linia din drepta
	for (int i = top_y + 1; i <= bottom_y; i++)
		conOut(Right_x, i)<<"|";

	//logarea utilizatorului
	conOut(Message_x, Message_y) << "Username:";
	conOut(Message_x, Message_y + 1) << "";
	getInputFromConsole(username);
	cleanArena(conOut);
	conOut(Message_x, Message_y) << "Password:";
	conOut(Message_x, Message_y + 1) << "";
	getInputFromConsole(password);
	cleanArena(conOut);

	//verific daca exista acest utilizator
	std::string inUser;
	std::string inPas;
	while (logInFile >> inUser) {
		logInFile >> inPas;
		if (inUser == username && inPas == password) {
			conOut(Message_x, Message_y) << "Utilizatorul exista";
			isThere = true;
			break;
		}
	}
	if (!isThere) {
		conOut(Message_x, Message_y) << "Utilizatorul nu exista, a fost adaugat";
		logInFile.close();
		std::ofstream outFile("users.db", std::ios::app);
		outFile << username + " " + password + "\n";
	}
	conOut(Message_x, Message_y + 1) << "Apasa pe orice sa inceapa jocul...";
	char last = '\0';
	while (last == '\0') {
		last = _getch();
	}
	cleanArena(conOut);
	//linia de sus
	for (int i = Left_x; i <= Right_x; i++)
		conOut(i, top_y) << " ";
	//linia de jos
	for (int i = Left_x; i <= Right_x; i++)
		conOut(i, bottom_y) << " ";
	//linia din stanga
	for (int i = top_y + 1; i <= bottom_y; i++)
		conOut(Left_x, i) << " ";
	//linia din drepta
	for (int i = top_y + 1; i <= bottom_y; i++)
		conOut(Right_x, i) << " ";
	user = username;
}

void LoginInterface::endGame(UserInterface::ConsoleOutput conOut,  bool gameOver, bool win, int scor)
{
	for (int i = Left_x; i <= Right_x; i++)
		conOut(i, top_y) << "_";
	//linia de jos
	for (int i = Left_x; i <= Right_x; i++)
		conOut(i, bottom_y) << "_";
	//linia din stanga
	for (int i = top_y + 1; i <= bottom_y; i++)
		conOut(Left_x, i) << "|";
	//linia din drepta
	for (int i = top_y + 1; i <= bottom_y; i++)
		conOut(Right_x, i) << "|";
	if (gameOver) {
		conOut(Message_x, Message_y) << "Ai pierdut!";
		conOut(Message_x, Message_y + 1) << "Scor: " << scor;
	}
	if (win) {
		conOut(Message_x, Message_y) << "Ai castigat!";
		conOut(Message_x, Message_y + 1) << "Scor: " << scor;
	}
	conOut(Message_x, Message_y + 2) << "Apasa pe orice sa iesi...";
	char last = '\0';
	while (last == '\0') {
		last = _getch();
	}
}
