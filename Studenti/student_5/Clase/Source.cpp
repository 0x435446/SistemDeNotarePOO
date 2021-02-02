#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <chrono>
#include "Entity.h"
#include "Zombie.h"
#include "PeaShooter.h"
#include "LoginInterface.h"
#include "Game.h"
#include <conio.h>
#include <string>
#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5
#define Left_x 50
#define top_y 15
#define Right_x 110
#define bottom_y 25

using namespace std::chrono;

void doLoadingBar()
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	static auto begin = steady_clock::now();
	static int col = COL_FIRST_STAR_POSITION;
	static std::string printedChar = "*";

	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > 150)
	{
		begin = end;
		conOut(ROW_TITLE + 1, col) << printedChar;
		if (col >= COL_FIRST_STAR_POSITION + 4 * COL_DISTANCE_BETWEEN_STARS) {
			if (printedChar == "*")
			{
				printedChar = " ";
			}
			else
			{
				printedChar = "*";
			}
			col = COL_FIRST_STAR_POSITION;
		}
		else
		{
			col += COL_DISTANCE_BETWEEN_STARS;
		}
	}
}

void drawArena() {

}

int main(void)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	/*conOut(ROW_TITLE, COL_FIRST_STAR_POSITION) << "Loading cool game now...";
	conOut(ROW_TITLE + 1, COL_FIRST_STAR_POSITION ) << "Loading cool game now...";*/
	/*while (true)
	{
		
	}*/

	std::string username;
	LoginInterface::start(conOut, username);
	Game game(conOut);
	game.start();

	auto sunTimer = std::chrono::system_clock::now();
	auto plantTimer = std::chrono::system_clock::now();
	auto zombieTimer = std::chrono::system_clock::now();
	//while (!(game.getGameOver() || game.getWin())) 
	while(true){
		std::string action = conIn.getUserActions();
		if (action != "")
		{
			conOut(1,1) << action;
		}
		game.update(conIn.getMousePos(), conIn.getHasDoubleClicked());
		game.sunSpawn(sunTimer);
		game.plantSpawn(plantTimer);
		game.zombieSpawn(zombieTimer);
		if (game.getGameOver() || game.getWin())
			break;
	}
	game.gameClear();
	LoginInterface::endGame(conOut, game.getGameOver(), game.getWin(), game.getScor());
	std::ofstream scorOut("score.txt", std::ios::app);
	scorOut << username << " " << game.getScor() << "\n";
	return 0;
}
/*
TO DO LIST:
	-login-ul, salvarea intr-un fisier deschis cu append DONE
	-logarea tuturor chestiilor intamplate
	-IDrawable interfata, get/set glyph/X/Y DONE
	-Drawable cu implementarea
	-Entity cu interactWith(Z,Pp,P) si interact(entity) DONE
	-Zombie care are hp si un timmer intern de attack 
	-PeaShooter same ca zombie
	-Pea doar ca sa aiba cu ce sa interactioneze zombie ul

	-fac o clasa game
		-> are un start care deseneaza harta
		-> are un draw everything

*/

