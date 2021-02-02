#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <chrono>
#include <thread>
#include "Lane.h"
#include "Zombie.h"
#include "Plant.h"
#include "Projectile.h"
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include "Board.h"
#include "History.h"
#include "Level.h"
#include <sstream>
#include "Level.h"

#include "ErrorSuns.h"
#include <random>
#include <cstdlib>


class Lane;

using namespace std::chrono;


void block(int nr_milliseconds) {
	static auto begin = steady_clock::now();
	
	auto end = steady_clock::now();
	if (duration_cast<milliseconds>(end - begin).count() > nr_milliseconds)
	{
		begin = end;
	}
}

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


void drawPlantSelection() {
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

	
	string plants[5] = {"Peashooter", "Sunflower", "Cherry Bomb", "Wall-nut", "Snow Pea"};

	for (int i = 0; i < 5; i++) {
		int x = X;
		int position = Y + i * 5;
		conOut(position, 0) << to_string(position) + ")"+plants[i];
	}
	
}

void drawSuns(int* suns) {
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 0; i < 9; i++) {
		if(suns[i] == 1){
			conOut(SUNS_POSITION, X + i*2) << "o";
		}else{
			conOut(SUNS_POSITION, X + i * 2) << " ";
		}
	}
}

void emptySuns() {
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 0; i < 9 * 2; i += 2) {
		conOut(SUNS_POSITION, X + i) << " ";
	}
}


template <typename T>
std::string NumberToString(T Number)
{
	std::ostringstream ss;
	ss << Number;
	return ss.str();
}

std::string n2s(int number) {
	return NumberToString<int>(number);
}

Lane* generateEmptyLane() {
	Lane* lane = new Lane();
	return lane;
}




vector<int> get_integers_from_string(string str)
{
	vector<int> result;
	stringstream ss;

	ss << str;

	string temp;
	int found;
	while (!ss.eof()) {

		ss >> temp;

		if (stringstream(temp) >> found) {
			result.push_back(found);
		}
			

		
	}
	return result;
}

class Utils {
private:
public:
	static int generate_random_number(int start, int end) {
		random_device dev;
		mt19937 rng(dev());
		uniform_int_distribution<mt19937::result_type> distribution_start_end(start, end); 

		
		return distribution_start_end(rng);
	}
};


class MouseEventHandler {
private:
	Level* level;
	static MouseEventHandler* theInstance;
	Entity* selected_entity = NULL;
	type selected_plant = NONE;
	int collected_suns = 0;

	MouseEventHandler() {

	}

	int suns[9] = { 0 };

	
public:
	static MouseEventHandler* get_instance() {
		if (MouseEventHandler::theInstance == NULL) {
			MouseEventHandler::theInstance = new MouseEventHandler();

			// TODO: remove hard-coding
			MouseEventHandler::theInstance->suns[0] = 1;
			MouseEventHandler::theInstance->suns[8] = 1;
		}
		return MouseEventHandler::theInstance;
	}

	void set_level(Level* level) {
		this->level = level;
	}

	int get_plant_position_for_xy(int x, int y) {
		int position = (x - 40) / 2;
		return position;
	}

	int get_lane_number_for_xy(int x, int y) {
	
		if (x >= 40 && x <= 56 && y >= 12 ) {
			int lane_number = (y - Y) / 5;
			if (lane_number >= 5) {
				return 4; // only lanes 1 through 4 exist
			}
			return lane_number;
		}
		return -1; // NOT A VALID LANE POSITION
		
	}

	void handle_event(int x, int y) {
		History::debug("handle_event(" + to_string(x) + ", "+to_string(y)+")");
		if (y == 7 && (x >= 10 && x <= 26)) {
			int position = (x - 10) / 2;
			History::debug("Sun selected: " + to_string(position));
			if (suns[position] == 1) {
				suns[position] = 0;
				collected_suns += SUN_PER_COLLECTED_SUN;
			}
			return;
		}
		if (selected_plant == NONE) {
			type plant_found = NONE;
			ErrorSuns err_suns;
			if (x <= 12) {
				if (y == 12) {
					History::debug("Peashooter selected");
					
					plant_found = PLANT_PEASHOOTER;
				}
				else if (y == 17) {
					History::debug("Sunflower selected");
					plant_found = PLANT_SUNFLOWER;
				}
				else if (y == 22) {
					History::debug("Cherry Bomb selected");
					plant_found = PLANT_CHERRY_BOMB;
				}
				else if (y == 27) {
					History::debug("Wall-nut selected");
					plant_found = PLANT_WALLNUT;
				}
				else if (y == 32) {
					History::debug("Snow Pea selected");
					plant_found = PLANT_SNOW_PEA;
				}
			}

			if (plant_found != NONE) {
				if (Plant::get_cost(plant_found) > this->collected_suns) {
					History::debug("Insufficient suns");
					throw err_suns;
				}
				selected_plant = plant_found;
			}
			
			
		}
		else {
			// plant has been selected, check to see if it can be placed on the lane
			// a lane number is only calculated here if a plant has been previously selected
			int lane_number = get_lane_number_for_xy(x, y);
			if (lane_number != -1) {
				int position = get_plant_position_for_xy(x, y);
				History::debug("Checking lane number (" + to_string(x) + ", " + to_string(y) + ") = " + to_string(lane_number));
				History::debug("PLACING PLANT AT: (" + to_string(x) + ", " + to_string(y) + "), position = "  + to_string(position));
				Lane* lane = level->get_lanes()[lane_number];
				Plant* plant = NULL;
				plant = new Plant(selected_plant, lane);
				lane->place_entity(plant, position);
				collected_suns -= plant->get_plant_cost() / 2;
				selected_plant = NONE;
			}
			else {
				History::debug("Cannot place plant at (" + to_string(x) + ", " + to_string(y) + ") ");
			}

		}
	}

	int* get_suns() {
		return this->suns;
	}



	void generate_random_sun() {
		int nr_suns_already_assigned = 0;
		for (int i = 0; i < 9; i++) {
			nr_suns_already_assigned += suns[i];	
		}
		if (nr_suns_already_assigned == 9) {
			// all suns have been assigned
			return;
		}
		bool has_been_assigned = false;
		while (!has_been_assigned) {
			int random_int = Utils::generate_random_number(0, 8); // random number between 0 and 8 (inclusive)
			
			if (suns[random_int] == 1) {
				continue; 
			}
			History::debug("Setting sun: " + to_string(random_int));
			suns[random_int] = 1;
			has_been_assigned = true;
		}
		

	}

	int& get_collected_suns() {
		return this->collected_suns;
	}
};

MouseEventHandler* MouseEventHandler::theInstance = NULL;


void displayErrorMessage(string message) {
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(43, 43) << message;
}

void clearErrorMessage() {
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 0; i < 30; i++) {
		conOut(43, 43+i) << " ";
	}
}

void clearScreen() {
	std::system("cls");
}


bool is_game_over(Level* level) {
	vector<Lane*>& lanes = level->get_lanes();
	for (int i = 0; i < lanes.size(); i++) {
		Lane* lane = lanes[i];
		vector<Entity*> zombies_at_0 = lane->get_zombies_at_position(0);
		for (int j = 0; j < zombies_at_0.size(); j++) {
			Entity* z = zombies_at_0[j];
			if (z != NULL && z->get_hp() > 0) {
				return true;
			}
		}
	}
	return false;
}

int main(void)
{

	string player_name;
	cout << "Your name: ";
	cin >> player_name;
	int lvl;
	
	do {
		cout << "Level (1-3): ";
		cin >> lvl;

	} while (lvl < 1 || lvl > 3);
	clearScreen();

	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

	 // level can be 1 to 3
	Level* level = new Level(lvl);
	MouseEventHandler::get_instance()->set_level(level);



	int iteration = 0;
	while (true)
	{

		conOut(0, 2) << "Player: " + player_name;
		iteration++;
		if (is_game_over(level)) {
			break;
		}

		
		int rand = Utils::generate_random_number(0, 100);
		int lane_numbers = level->get_lanes().size();
		if (rand % 79 == 0) {
			// enum type ZOMBIE, ZOMBIE_POLE_VAULTING, ZOMBIE_BUCKET_HEAD, ZOMBIE_SUPER_ZOMBIE, PROJECTILE, NONE };
			int zombie_type = Utils::generate_random_number(0, 3);
			int lane_fz = Utils::generate_random_number(0, lane_numbers - 1);
			History::debug("GENERATING ZOMBIE: " + to_string(zombie_type));
			Zombie* z = NULL;
			switch (zombie_type) {
			case 0:
				z = new Zombie(ZOMBIE, level->get_lanes()[lane_fz]);
				History::debug("GENERATING ZOMBIE: ZOMBIE");
				break;
			case 1:
				z = new Zombie(ZOMBIE_POLE_VAULTING, level->get_lanes()[lane_fz]);
				History::debug("GENERATING ZOMBIE: ZOMBIE_POLE_VAULTING");
				break;
			case 2:
				z = new Zombie(ZOMBIE_BUCKET_HEAD, level->get_lanes()[lane_fz]);
				History::debug("GENERATING ZOMBIE: ZOMBIE_BUCKET_HEAD");
				break;
			case 3:
				z = new Zombie(ZOMBIE_SUPER_ZOMBIE, level->get_lanes()[lane_fz]);
				History::debug("GENERATING ZOMBIE: ZOMBIE_SUPER_ZOMBIE");
				break;
			
				
			}
			level->get_lanes()[lane_fz]->place_entity(z, 8);


		}
		

		conOut(SUNS_POSITION - 3, X ) << "Suns: " << to_string(MouseEventHandler::get_instance()->get_collected_suns());
		level->drawSurfaces(30);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
		drawPlantSelection();
		// once in a while generate a random sun
		int series = Utils::generate_random_number(0, 500);

		if (series < 33) { // once (almost) every three iterations
			 MouseEventHandler::get_instance()->generate_random_sun();
		}

		drawSuns(MouseEventHandler::get_instance()->get_suns());
		level->tick_lanes();
		std::this_thread::sleep_for(std::chrono::milliseconds(TICK_INTERVAL));

		
		std::string action = conIn.getUserActions();
		if (action != "")
		{
			conOut(41, 2) << action;
			
			if (action.find("double") != std::string::npos) {
				// action double-clicked
				History::debug("\n------------------\n");
				vector<int> ints_in_command = get_integers_from_string(action);
				for (int i = 0; i < ints_in_command.size(); i++) {
					History::debug("Double click: " + to_string(ints_in_command[i]));
					try{
					MouseEventHandler::get_instance()->handle_event(ints_in_command[0], ints_in_command[1]);
					}
					catch (ErrorSuns sunError) {
						displayErrorMessage("INSUFFICIENT suns");
					}
				}
				History::debug("\n------------------\n");
				
			}
			else if (action.find("moved") != std::string::npos) {
				// mouse moved
			}
			
		
		}
	}
	clearScreen();
	conOut(40, 20) << "GAME OVER";

	History::add_player_score(player_name, Level::player_score);
	map<string, int> player_scores = History::get_player_scores();
	map<string, int>::iterator it;

	int pos_mesaj = 0;
	for (it = player_scores.begin(); it != player_scores.end(); it++)
	{
		conOut(20 + pos_mesaj, 30 ) << it->first + " " + to_string(it->second);
		pos_mesaj++;
	}
	

	system("pause");

	return 0;
}

