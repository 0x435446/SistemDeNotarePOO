#pragma once
#include "Easy.h"
#include "Sori.h"
#include "Map.h"
#include "Score_board.h"



class Select_Lvl
{
private:
	Easy L1;
	Easy L2;
	Easy L3;
	Easy L4;
	Easy L5;
	string Name;
public:
	void Set_Name(string Name);
	void Start_Lvl();
	void Level_Easy();
	void Level_Medium() ;
	void Level_Hard() ;
	void Choose(int x) ; 
};

