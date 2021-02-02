#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include <time.h>
#include <chrono>
#include <vector>
#include <algorithm>
#include <utility>
#include <fstream>
#include <iostream>
#include <conio.h>
#include "Sunflower.h"
#include "Peashooter.h"
#include "Zombie.h"
#include <random>
#include "special_pos.h"

fstream actions_out("actions.txt", ios::app);

using namespace std;

void draw_terrain(int level) {
	vector<int> lanes;
	if (level == 1) {
		lanes = vector<int>{ 3, 4 };
	}
	else if (level == 2) {
		lanes = vector<int>{ 2, 3, 4, 5 };
	} 
	else {
		lanes = vector<int>{1, 2, 3, 4, 5, 6 };
	}
	UserInterface::ConsoleOutput out = UserInterface::ConsoleOutput::getInstance();
	int row = 5;
	for (int i = 1; i <= 6; ++i) {
		for (int col = 3; col <= 10; ++col) {
			out(row, col) << "-";
		}
		if(find(lanes.begin(), lanes.end(), i) != lanes.end())
			for (int col = 10; col <= 150; ++col) {
				out(row, col) << "-";
			}
		row += 5;
	}
	for (row = 2; row <= 30; ++row)
		out(row, 10) << "|";


	auto check_matrix = matrix_special_position();
	int line1 = 1, line2 = 2, line3 = 3, line4 = 4, line5 = 5;
	int count_line = 0;
	for (auto& i : check_matrix) {
		count_line++;
		for (auto& j : i)
			for (auto k = 0; k < 5; k++) {
				if (level == 3) out(j.y1 + k, j.x1) << "|";
				if (level == 2) {
					if(count_line  != 1 && count_line != 5)
						out(j.y1 + k, j.x1) << "|";
				}
				if (level == 1) {
					if(count_line == 3)
						out(j.y1 + k, j.x1) << "|";
				}
			}
	}

}


int Register() {
	fstream fout("logs.log", ios::app);
	UserInterface::ConsoleOutput out = UserInterface::ConsoleOutput::getInstance();
	string username, password;
	char k;
	out(1, 3) << "Username: ";
	do {
		k = _getch();
		if (k != '\r') {
			cout << k;
			username += k;
		}
	} while (k != '\r');
	out(2, 3) << "Password: ";
	do {
		k = _getch();
		if (k != '\r') {
			cout << "*";
			password += k;
		}
	} while (k != '\r');

	fout << username << " " << password << endl;
	for(int i = 0; i < username.length()+10; ++i)
		out(1, 3 + i) << " ";
	for(int i = 0; i < password.length()+10; ++i)
		out(2, 3 + i) << " ";
	return 1;
}


void select_suns(int& points, vector<int>& place_suns, pair<int, int> position) {
	UserInterface::ConsoleOutput out = UserInterface::ConsoleOutput::getInstance();
	if (position.first >= 1 && position.first <= 3)
		if (position.second >= 10 && position.second <= 150)
			for (int i = 0; i < 9; ++i)
				if (position.second >= 15 * (i + 1) && position.second <= 15 * (i + 2) + 3 && place_suns[i]) {
					actions_out << "Soare selectat\n";
					out(2, 15 * (i + 1)) << "   ";
					place_suns[i] = 0;
					points++;
					break;
				}
	out(2, 5) << points;
}

vector<pair<int, int>> get_plant_positions() {
	pair<int, int> ref{ 3, 5 };
	vector<pair<int, int>> pos;
	for (int i = 1; i <= 5; ++i) {
		ref.first += 5;
		pos.push_back(ref);
	}
	return pos;
}

void generate_plants(vector<int> &place_plants, vector<Sunflower> &sunflowers, vector<Peashooter> &peashooters) {
	vector<pair<int, int>> plant_positions = get_plant_positions();

	random_device rd;
	mt19937 eng(rd());
	uniform_int_distribution<> distr(0, 4);
	int cnt = 0;

	auto j = plant_positions.begin();
	for (auto i = 0; i < place_plants.size(); i++) {
		if (distr(eng) % 2 == 0) {
			Sunflower my_sunflower("sunflower", 'S', j->first, j->second, 5, 2, 0);
			my_sunflower.change_vect_pos(cnt++);
			my_sunflower.vect_pos = i;
			sunflowers.push_back(my_sunflower);
			place_plants[i] = 1;
		}
		else {
			Peashooter my_peashooter(3, "peashooter", 'P', j->first, j->second, 4, 1, 0);
			my_peashooter.change_vect_pos(cnt++);
			my_peashooter.vect_pos = i;
			peashooters.push_back(my_peashooter);
			place_plants[i] = 1;
		}
		j++;
	}

	for (auto& i : sunflowers) i.draw();
	for (auto& i : peashooters) i.draw();
}

vector<special_position> plants_vect_pos() {
	special_position aux;
	vector<special_position> pos;
	aux.x1 = 1;
	aux.y1 = 3;
	aux.x2 = 7;
	aux.y2 = 10;
	pos.push_back(aux);
	for (int i = 1; i <= 4; ++i) {
		aux.y1 += 5;
		aux.y2 += 5;
		pos.push_back(aux);
	}
	return pos;
}

vector<vector<pair<int, int>>> get_pos_matrix() {
	UserInterface::ConsoleOutput out = UserInterface::ConsoleOutput::getInstance();
	pair<int, int> init{ 8, 15 };
	vector<vector<pair<int, int>>> pos_matrix;
	for (int i = 0; i < 5; ++i) {
		init.second = 15;
		vector<pair<int, int>> aux;
		for (int j = 0; j < 9; ++j) {
			aux.push_back(init);
			init.second += 15;
		}
		pos_matrix.push_back(aux);
		init.first += 5;
	}

	return pos_matrix;
}


void select_plant_s(Sunflower& plant, int& points, double& suntime) {

	UserInterface::ConsoleOutput out = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput in = UserInterface::ConsoleInput::getInstance();
	pair<int, int> position{ 0 , 0 };
	plant.changealias(' ');
	plant.draw();
	do {
		position = in.mouseEventPositions();
	} while (!(position.first && position.second));

	auto pos_matrix = get_pos_matrix();
	auto check_matrix = matrix_special_position();

	for(int i = 0; i < check_matrix.size(); ++i)
		for (int j = 0; j < check_matrix[i].size(); ++j) {
			if (check_pos(check_matrix[i][j], position)) {
				plant.change_position(pos_matrix[i][j].first, pos_matrix[i][j].second);
			}
		}

	plant.changealias('S');
	plant.draw();
	points -= plant.getCost();
	suntime -= 0.5;
	out(2, 5) << points;
}

void select_plant_p(Peashooter& plant, int& points) {
	UserInterface::ConsoleOutput out = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput in = UserInterface::ConsoleInput::getInstance();
	pair<int, int> position{ 0 , 0 };
	plant.changealias(' ');
	plant.draw();
	do {
		position = in.mouseEventPositions();
	} while (!(position.first && position.second));

	auto pos_matrix = get_pos_matrix();
	auto check_matrix = matrix_special_position();

	for (int i = 0; i < check_matrix.size(); ++i)
		for (int j = 0; j < check_matrix[i].size(); ++j) {
			if (check_pos(check_matrix[i][j], position)) {
				plant.change_position(pos_matrix[i][j].first, pos_matrix[i][j].second);
				plant.attack_pos.first = pos_matrix[i][j].first;
				plant.attack_pos.second = pos_matrix[i][j].second;
			}
		}

	plant.changealias('P');
	plant.draw();
	points -= plant.getCost();
	out(2, 5) << points;

}


void select_plants(vector<Sunflower>& sunflowers, vector<Peashooter>& peashooters, pair<int, int> position, int& points, double& suntime, vector<int> &place_plants) {

	UserInterface::ConsoleOutput out = UserInterface::ConsoleOutput::getInstance();
	vector<special_position> click_area = plants_vect_pos();

	for (int i = 0; i < click_area.size(); ++i) {
		if (check_pos(click_area[i], position)) {
			for(auto &j : sunflowers)
				if (j.get_vect_pos() == i && j.getCost() <= points) {
					actions_out << "Sunflower selectat timpul de aparitie o sa scada\n";
					select_plant_s(j, points, suntime);
					j.change_on_battle();
					place_plants[j.vect_pos] = 0;
				}
			for(auto &j : peashooters)
				if (j.get_vect_pos() == i && j.getCost() <= points) {
					actions_out << "Peashotter selectat\n";
					select_plant_p(j, points);
					j.change_on_battle();
					place_plants[j.vect_pos] = 0;
				}
				
		}
	}
	
}

void Start(int level, Zombie z) {
	actions_out << "Nivelul 3 a inceput\n";
	UserInterface::ConsoleOutput out = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	pair<int, int> position;
	vector<int> place_plants{ 0 ,0, 0, 0 ,0 };
	vector<int> place_suns{ 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	vector<Sunflower> sunflowers;
	vector<Peashooter> peashooters;	
	int points = 0;
	double sun_time = 5;
	out(2, 5) << points;

	random_device rd; 
	mt19937 eng(rd()); 
	uniform_int_distribution<> distr1(0, 4);
	uniform_int_distribution<> distr2(0, 8);
	int pos;

	draw_terrain(level);
	actions_out << "Teren desenat\n";
	generate_plants(place_plants, sunflowers, peashooters);
	actions_out << "Plantele au fost generate\n";
	chrono::time_point<chrono::system_clock> start, end, start_attack, end_attack;
	start = std::chrono::system_clock::now();
	start_attack = std::chrono::system_clock::now();;
	while (true) {
		position = conIn.mouseEventPositions();
		auto end = chrono::system_clock::now();
		auto end_attack = chrono::system_clock::now();
		chrono::duration<double> elapsed = end - start;
		chrono::duration<double> elapsed_attack = end_attack - start_attack;
		if (elapsed.count() > sun_time) {
			while (pos = distr2(eng)) {
				if (!place_suns[pos]) {
					actions_out << "Soare aparut\n";
					out(2, 15 * (pos + 1)) << "SUN";
					place_suns[pos] = 1;
					break;
				}
			}
			start = end;
		}
		if (find(place_plants.begin(), place_plants.end(), 1) == place_plants.end()) {
			for (auto& i : place_plants)
				i = 0;
			generate_plants(place_plants, sunflowers, peashooters);
		}
		select_suns(points, place_suns, position);
		select_plants(sunflowers, peashooters, position, points, sun_time, place_plants);
		z.draw();
		if (elapsed_attack.count() > 0.7) {
			z.draw();
			for (auto& i : peashooters) {
				if (i.get_on_battle()) {
					start_attack = end;
					actions_out << "Peashooteri activi trag\n";
					i.action();
					z.damage(i.attack_pos);
					out(i.attack_pos.first, i.attack_pos.second) << ".";
					if(i.attack_pos.second-6 != i.get_position().second)
						out(i.attack_pos.first, i.attack_pos.second-6) << " ";
				}
			}
		}
	}
	
}

Zombie zombie_gen(int level) {
	vector<vector<pair<int, int>>> pos_matrix = get_pos_matrix();
	int col = 147;
	Zombie zombie(pos_matrix[2][8].first, col, 1, 'Z');
	return zombie;
}

int main(void)
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	string log = "Login";
	string reg = "Register";
	Zombie z = zombie_gen(1);
	actions_out << "Zombie generat\n";
	conOut(20, 70) << log;
	conOut(20, 79) << reg;
	pair<int, int> position;
	int registration = 0;
	int level = 3;
	while(!registration)
	{
		string action = conIn.getUserActions();
		position = conIn.mouseEventPositions();
		if (action != "") conOut(41, 2) << action;
		if (position.first == 20 || position.first == 21 || position.first == 19) 
			if (position.second >= 79 && position.second <= 87) {
				log = "      ";
				reg = "        ";
				conOut(20, 70) << log;
				conOut(20, 79) << reg;
				registration = Register();
				actions_out << "Utilizzator inregistrat\n";
			}
	}
	Start(level, z);
	return 0;
}

