#include "Level.h"



Level::Level()
{
}

Level::Level(int level_number)
{
	this->level_number = level_number;
	if (level_number == 1) {
		this->lanes.push_back(new Lane());
	}
	else if (level_number == 2) {
		this->lanes.push_back(new Lane());
		this->lanes.push_back(new Lane());
		this->lanes.push_back(new Lane());
	}
	else if (level_number == 3) {
		for (int i = 0; i < 5; i++) {
			this->lanes.push_back(new Lane());
		}
		
	}
}


Level::~Level()
{
}

vector<Lane*>& Level::get_lanes()
{
	return this->lanes;
}

void Level::drawSurface(int lane_num, int offset_to_right)
{
		static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();

		Lane* lane = this->lanes[lane_num];
		int position = Y + lane->get_lane_number() * 5;

		for (int i = 0; i < 9 * 2; i += 2) {
			conOut(position, X + offset_to_right + i) << "X";
		}
		std::vector<std::vector<Entity*>*> zombies = lane->get_zombies();
		vector<Entity*> plants = lane->get_plants();
		for (int i = 0; i < 9; i++) {
			// reset view 
			for (int j = 0; j < 4; j++) { // TODO: remove hardcoding
				conOut(position + j + 1, X + offset_to_right + i * 2) << " ";
				conOut(position + j + 1, X + offset_to_right + i * 2 + 1) << " ";
			}
		}
		for (int i = 0; i < 9; i++) {
			// place zombies
			for (int j = 0; j < zombies[i]->size(); j++) {
				if ((*zombies[i])[j] != NULL) {
					// zombies should be drawn one level under the plants 

					History::debug("DRAWING ZOMBIE: " + to_string((*zombies[i])[j]->get_type_id()));
					conOut(position + j + 2, X + offset_to_right + i * 2) << (*zombies[i])[j]->draw();
				}
				else {
					// zombie is dead
				}


			}

		}
		// place plants
		for (int j = 0; j < plants.size(); j++) {
			if (plants[j] != NULL) {
				conOut(position + 1, X + offset_to_right + j) << (*plants[j]).draw();
			}
		}
		vector<Entity*>& projectiles = lane->get_projectiles();
		for (int j = 0; j < projectiles.size(); j++) {
			if (projectiles[j] != NULL) {
				conOut(position + 1, X + offset_to_right + j * 2) << (*projectiles[j]).draw();
			}
		}
}

void Level::drawSurfaces(int offset_to_right)
{
	for (int i = 0; i < this->lanes.size(); i++) {
		drawSurface(i, 30);
	}
}

void Level::tick_lanes()
{
	for (int i = 0; i < this->lanes.size(); i++) {
		this->lanes[i]->tick();
	}
}

int Level::compute_score()
{
	return Level::player_score;
}


int Level::player_score = 0;