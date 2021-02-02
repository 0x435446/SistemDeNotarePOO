#pragma once
#include <string>
class Credentials
{
private:
	std::string Name;
	std::string Password;
public:
	//Constructors
	Credentials();
	Credentials(const std::string& Name, const std::string& Password);
	Credentials(const Credentials&);
	//Destructor
	~Credentials();
	//Get
	std::string getName()const;
	std::string getPassword()const;
	//Set
	void setName(const std::string& Name);
	void setPassword(const std::string& Password);
};

