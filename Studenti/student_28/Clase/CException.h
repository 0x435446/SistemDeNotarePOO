#pragma once
#include<iostream>
#include<string>
#include"Codes.h"

class CException
{
	int m_cod;
	std::string m_message;
public:
	CException(int cod,const std::string& message);
	void printError();
	~CException();
};

