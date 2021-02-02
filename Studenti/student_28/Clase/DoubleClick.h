#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"ConsoleInput.h"
#include"ConsoleOutput.h"

class DoubleClick
{
	int x, y;
public:
	DoubleClick(const std::string& action);
	bool isNumber(char *s);
	int returnX();
	int returnY();
	~DoubleClick() {};
};

