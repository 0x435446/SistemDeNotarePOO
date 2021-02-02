#define _CRT_SECURE_NO_WARNINGS
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Afisare.h"
#include "Sun.h"
#include "Action.h"
#include "Entity.h"
#include "Log.h"

#include<chrono>
#include<time.h>
#include<conio.h>
#include<Windows.h>


//planta sa atace!
//zombie jumper
//clasa projectile



int main(void)
{

	static UserInterface::ConsoleOutput &conOut = UserInterface::ConsoleOutput::getInstance();
	static UserInterface::ConsoleInput &conIn = UserInterface::ConsoleInput::getInstance();
	
	Afisare &printer = Afisare::getInstance();
	Sun &sun_generator = Sun::getInstance();
	Action &checker = Action::getInstance();
	Log loger;

	int contor_level = 1;
	int check_spawn = 0;
	int contor_end;
	int previous_spawn=0;
	int zombie_attack;
	std::string player_name;
	

	
	//printez elementele stabile pe tot intregul jocului
	
	printer.printTitle();

	//informatii de logare
	//conIn.getUserActions();
	loger.log_in();
	player_name = loger.get_player_name();
	system("cls");
	conOut(13, 12) << player_name;

	

	printer.Board_sun();
	printer.Board_plants(); 
	sun_generator.set_score();
	
	

	// afisez  tabla de joc pentur level 1

	while (contor_level != 0)
	{
		std::string action = conIn.getUserActions();
		
		

		sun_generator.generate();
		printer.Board_level_one();
		checker.plants_attack();
		checker.move_zombie();
		contor_end = checker.end_game();
		if (contor_end==1)
		{
			checker.end_game();
			contor_level = 0;
		}
		if ((check_spawn==0)||(check_spawn==1))
		{
			if (check_spawn==0)
			{
				check_spawn = checker.spawn_zobie("Zombie", contor_level,previous_spawn);
				previous_spawn = check_spawn;
			}
			if (check_spawn==1)
			{
				check_spawn = checker.spawn_zobie("Bucket", contor_level,previous_spawn);
				previous_spawn = check_spawn;
			}
			
		}
		
		zombie_attack = checker.attack_zombie();

		if (action != " ")
		{
			sun_generator.collect(action);
			int score = sun_generator.get_score();
			
			int cost = checker.place_plants(action, score, contor_level);
			sun_generator.buy_plant(cost);
			sun_generator.print_score();
	
		}	
	} 


	return 1;
}

