#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "PooVsZom.h"
#include "Entity.h"
#include <conio.h>
int main() {
	std::string username;
	std::string password;
	std::string inUser;
	std::string inPas;
	std::ifstream logInFile("users.database");
	int level;
	bool exists = false;
	if (!logInFile.is_open())
		throw std::exception("Nu exista fisierul users.db, creaza unu!");

	try {
		std::cout << "Username: ";
		std::cin >> username;
		std::cout << "\nPassword: ";
		std::cin >> password;
		while (logInFile >> inUser) {
			logInFile >> inPas;
			if (inUser == username && inPas == password) {
				std::cout << "\nUtilizatorul exista, se va relua nivelul daca exista unu inceput";
				exists = true;
				break;
			}
		}
		logInFile.close(); 
		if (!exists) {
			std::cout << "\nUtilizatorul nu exista, a fost creat si introdus in baza de date";
			logInFile.close();
			std::ofstream outFile("users.database", std::ios::app);
			outFile << username + " " + password + "\n";
		}
		std::cout << "\nApasa pe orice sa inceapa jocul...";
		char last = '\0';
		while (last == '\0') {
			last = _getch();
		}
		PooVsZom game(1);
		if (exists) {
			std::ifstream saveFile(username + ".save");
			if (saveFile.is_open()) {
				saveFile >> level;
				saveFile.close();
				
			}
		}
		else {
			level = 1;
		}
		game.setLevel(level);
		if (game.constructConsole(90, 60, 10, 10))
			game.start();
		if (game.getWin()) {
			std::cout << "Ai castigat nivelul " << level << "\nCu scorul:"<<game.getScor();
			std::ofstream save(username + ".save");
			save << level + 1;
		}
		else {
			std::cout << "Ai pierdut...\n";
		}
		
	}
	catch (...) {

	}
	
	/*
			0000VV0000 0000VV0000 000V00V000 000V00V000 00V0000V00 0rrr00rrr0 rararrarar rnrnrrnrnr 0rrr00rrr0 0000000000
	*/
	system("pause");
	return 0;
}