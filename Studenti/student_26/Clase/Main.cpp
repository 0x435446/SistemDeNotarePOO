#include "Game.h"

int main()
{
	Game game;
	game.ConstructConsole(160, 80, 8, 8);
	game.Start();
	return 0;
}