#pragma once
#include <iostream>
#include <vector>

#include "Resurse_Sun.h"
#include "ConsoleInput.h"
#include "ConsoleOutput.h"

class Calcule:
    public Resurse_Sun,
    public UserInterface::ConsoleInput,
    public UserInterface::ConsoleOutput
{
protected:
    std::vector<int> vector_soare;
    UserInterface::ConsoleOutput conOut;
    UserInterface::ConsoleInput conIn;
public:
    void InitSunVector();
    int CheckInputPlante(int x, int y,int& select);
    void CheckInputSoare(int x, int y);
    void DrawSun();
    void DrawPeaShooter(int x,int y);
    void DrawSunFlower(int x, int y);
    void DrawWallNut(int x, int y);
    int NumSun = 0;
    Calcule();
    ~Calcule();
};

