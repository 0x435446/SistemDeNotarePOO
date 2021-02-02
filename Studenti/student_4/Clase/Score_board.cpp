#include "Score_board.h"

void Score_board::Add_Your_Score(string Nume_Player, int score)
{
	std::ofstream outfile("Scooooreboard.txt");

	outfile << Nume_Player<<"	:	"<<score << std::endl;

	outfile.close();
}

Score_board* Score_board::instance()
{
	if (Score_board::Instanta == NULL)
		Score_board::Instanta == new Score_board();
	return Score_board::Instanta;
}
Score_board* Score_board::Instanta = NULL;