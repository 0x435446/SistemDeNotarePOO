#pragma once
#include <string>
#include<iostream>
#include<Windows.h>
#include <fstream>
using namespace std;
class Users
{

public:
	Users();
	~Users();

	static void takeCredentials();
	static void putCredentials(string nume ,string parola);
	static int searchUser(string nume, string parola);
};

