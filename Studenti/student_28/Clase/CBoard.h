#pragma once
#include<iostream>
#include"ConsoleInput.h"
#include"ConsoleOutput.h"

class CBoard
{
	static CBoard* instance;
	void drawEdges();
	CBoard(const int&);
	void draw1();
	void draw2();
	void draw3();
	~CBoard();
public:
	static CBoard& GetInstance(const int &lvl);
	static void DestroyInstance();
};

