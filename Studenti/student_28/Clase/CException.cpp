#include "CException.h"



CException::CException(int cod,const std::string& message)
	:m_cod(cod),m_message(message)
{
}

void CException::printError()
{
	std::cout << "Eroare: " << m_message << std::endl;
}


CException::~CException()
{
}
