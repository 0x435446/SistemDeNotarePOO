#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Entity.h"
#include "ExceptionBadPosition.h"


using namespace std;

class Entity;

class ExceptionBadPosition;



class Lane
{
private:
	int static lane_counter;
	int lane_number;
	vector<Entity*> plants;
	vector<Entity*> projectiles;
	vector<vector<Entity*>*> zombies;
	int no_of_ticks_total = 0;

	
	int no_of_plant_interval_ticks = 0;
public:
	Lane();
	~Lane();

	vector<Entity*>& get_plants() {
		return this->plants;
	}

	Entity* get_last_plant() {
		for (int i = 8; i > 0; i--) {
			if (plants[i] != NULL) {
				return plants[i];
			}
		}
		return NULL;
	}

	vector<Entity*> get_zombies_at_position(int position_zombie) {
		vector<Entity*> result;
		if (position_zombie < 0) {
			return result;
		}
		if (position_zombie > 8) {
			return result;
		}

		vector<vector<Entity*>*>& zombies_on_lane = this->get_zombies();
		for (int i = 0; i < (*zombies_on_lane[position_zombie]).size(); i++)
		{
			
			Entity* zombie = (*zombies_on_lane[position_zombie])[i];
			result.push_back(zombie);
		}
		return result;

	}

	vector<Entity*> get_zombies_positions_for_cb_damage(int position) {
		vector<Entity*> all_zombies_to_take_damage;
		
		vector<Entity*> zombies_at_position_0 = get_zombies_at_position(position - 1);
		vector<Entity*> zombies_at_position_1 = get_zombies_at_position(position );
		vector<Entity*> zombies_at_position_2 = get_zombies_at_position(position + 1);

		all_zombies_to_take_damage.insert(std::end(all_zombies_to_take_damage), std::begin(zombies_at_position_0), std::end(zombies_at_position_0));
		all_zombies_to_take_damage.insert(std::end(all_zombies_to_take_damage), std::begin(zombies_at_position_1), std::end(zombies_at_position_1));
		all_zombies_to_take_damage.insert(std::end(all_zombies_to_take_damage), std::begin(zombies_at_position_2), std::end(zombies_at_position_2));

		return all_zombies_to_take_damage;
	}


	vector<vector<Entity*>*>& get_zombies() {
		return this->zombies;
	}

	vector<Entity*>& get_projectiles() {
		return this->projectiles;
	}

	/// place a zombie or plant
	void place_entity(Entity* ent, int position);
	void tick();

	void kill_zombie(Entity* zombie_to_kill) {
		// vector<vector<Entity*>*> zombies
		for (int i = 0; i < zombies.size(); i++) {
			for (int j = 0; j < zombies[i]->size(); j++) {
				Entity* zombie = (*zombies[i])[j];
				if (zombie != NULL && zombie == zombie_to_kill) {
					(*this->zombies[i])[j] = NULL;
				}
			}
		}
	}

	int get_lane_number();
};

