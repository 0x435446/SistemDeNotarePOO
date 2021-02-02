#define _CRT_SECURE_NO_WARNINGS
#include "Coordonate.h"
#include<string.h>


Coordonate::Coordonate(const std::string &action)
{
	char cuv[500];
	strcpy(cuv, action.c_str());
	char *p;
	if (strstr(cuv, "double"))
	{
		p=strtok(cuv, "(,)");
		p = strtok(NULL, "(,)");
		this->cx = atoi(p);
		p = strtok(NULL, "(,)");
		this->cy = atoi(p);
	}
	else
	{
		this->cx = 0;
		this->cy = 0;
	}
}


Coordonate::~Coordonate()
{
}
