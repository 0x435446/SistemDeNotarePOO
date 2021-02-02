#include "Credentials.h"

Credentials::Credentials():Name("Anonim"),Password("password")
{
}

Credentials::Credentials(const std::string& Name, const std::string& Password):Name(Name),Password(Password)
{
}

Credentials::Credentials(const Credentials& other)
{
	this->Name = other.Name;
	this->Password = other.Password;
}

Credentials::~Credentials()
{
}

std::string Credentials::getName() const
{
	return this->Name;
}

std::string Credentials::getPassword() const
{
	return this->Password;
}

void Credentials::setName(const std::string& Name)
{
	this->Name = Name;
}

void Credentials::setPassword(const std::string& Password)
{
	this->Password = Password;
}
