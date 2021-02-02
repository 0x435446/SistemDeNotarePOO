#pragma once#
#include <fstream>
#include <string>
using namespace std;

class Score_board
{
private:
	Score_board() {};
	static Score_board* Instanta;
public :
	static void Add_Your_Score(string Nume_Player, int score);
	static Score_board* instance();
};

