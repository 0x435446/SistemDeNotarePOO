#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Lane.h"
#include <map>

using namespace std;

class History
{
public:
	History();
	~History();

	static void add_player_score(string player_name, int score) {
		ofstream out;
		out.open("player_scores.txt", ios::app);
		out << player_name + " " + to_string(score)<< endl;
		out.close();
	}

	static map<string, int> get_player_scores() {
		map<string, int> result;
		ifstream in;
		in.open("player_scores.txt", ios::in);
		while (!in.eof())
		{
			string pn;
			int ps;
			in >> pn;
			in >> ps;
			result.insert(pair<string, int>(pn, ps));
		}
		in.close();
		return result;
	}



	static void debug(string message) {
		ofstream out;
		out.open("history.txt", ios::app);
		out << message << endl;
		out.close();
	}

	static void debug_lane(Lane* lane) {

		string debug_message_projectiles = "Lane Projectiles[" + to_string(lane->get_lane_number()) + "]";
		debug_message_projectiles += '\n';
		vector<Entity*>& projectiles = lane->get_projectiles();
		for (int i = 0; i < projectiles.size(); i++) {
			if (projectiles[i] != NULL) {
				debug_message_projectiles += to_string(projectiles[i]->get_id());
			}
			else {
				debug_message_projectiles += "x";
			}
		}
		debug_message_projectiles += '\n';

		string debug_message_zombies = "Lane Zombies[" + to_string(lane->get_lane_number()) + "]";
		vector<vector<Entity*>*> zombies = lane->get_zombies();
		for (int i = 0; i < zombies.size(); i++) { // zombie positions
			debug_message_zombies += "Position: " + to_string(i) + '\n';

			vector<Entity*>* zombies_at_position = zombies[i];
			for (int j = 0; j < zombies_at_position->size(); j++) {
				Entity* zombie = (*zombies_at_position)[j];
				if (zombie != NULL) {
					debug_message_zombies += "HP: " + to_string(zombie->get_hp());
					debug_message_zombies += "|";
				}
				debug_message_zombies += '\n';
			}
		}

		string debug_message_plants = "Lane plants[" + to_string(lane->get_lane_number()) + "]";
		debug_message_plants += '\n';
		vector<Entity*>& plants = lane->get_plants();
		for (int i = 0; i < plants.size(); i++) {
			if (plants[i] != NULL) {
				debug_message_plants += "P"; //to_string(plants[i]->get_id());
			}
			else {
				debug_message_plants += "X";
			}
		}
		debug_message_plants += '\n';

		ofstream out;
		out.open("history.txt", ios::app);
		out << "-------------------------------------------" << endl;
		out << debug_message_projectiles << endl;
		out << debug_message_zombies << endl;
		out << debug_message_plants << endl;
		out << "-------------------------------------------" << endl;
		out.close();
	}
};

