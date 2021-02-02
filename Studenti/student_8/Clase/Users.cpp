#include "Users.h"
#include <time.h>
using namespace std;
Users::Users()
{
}


Users::~Users()
{
}

void Users::takeCredentials()
{
	system("CLS");
	string nume ;
	int y;
	string parola;
    label1:
	
	cout<< "Pentru logarea la un cont apasati tasta 1 ,pentru crearea unui nou cont apasati tasta 2 ! \n";
	cin >> y;
	switch (y)
	{
	case 1:
	{
		cout << "Dati numele utilizatorului : ";
		cin >> nume;

		cout << "Dati parola utilizatorului : ";
		cin >> parola;
		if (searchUser(nume, parola) == 1)
		{

			cout << "Bine ati venit !";
			Sleep(1000);
		}
		else if (searchUser(nume, parola) == 0)
		{

			cout << "Parola sau username incorecte sau inexistente ! Mai incearca ! \n";
			Sleep(1000);
			goto label1;
		}
		else if (searchUser(nume, parola) == 2)
		{
			cout << "Parola incorecta ! Mai incearca ! \n";
			Sleep(1000);
			goto label1;

		}
		break;
	}
	case 2 :
	{
		cout << "Dati numele utilizatorului : ";
		cin >> nume;

		cout << "Dati parola utilizatorului : ";
		cin >> parola;
		if (searchUser(nume, parola) == 2)
		{

			cout << "Usernameul este deja luat incercati din nou !\n";
			Sleep(1000);
			goto label1;
		}
		else
			
				putCredentials(nume, parola);

		break;
	}
	default:
	{	cout << "Ati ales o optiune care nu este prezentata !";

		break;
	}
	}
}

void Users::putCredentials(string nume ,string parola)
{
	ofstream fout("Credentials.txt", fstream::app);
	fstream file;
	
	fout <<nume<<"\n"<<parola<<"\n";
	fout.close();

}

int Users::searchUser(string nume, string parola)
{
	string nume1, parola1;
	ifstream fin("Credentials.txt");
	if (!fin.is_open())
	{
		fin.close();
		ofstream fout("Credentials.txt", fstream::out);
		fout.flush();
		ifstream fin("Credentials.txt");
	}

	while (!fin.eof())
	{
		fin >> nume1;
		fin >> parola1;
		if (nume1 == nume && parola1 == parola)
		{
			fin.close();
			return 1;
		}
		else
			if (nume1 == nume)
			{
				fin.close();
				return 2;
			}
	    
	}
	fin.close();
	return 0;
	
}
