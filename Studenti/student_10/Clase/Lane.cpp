#include "Lane.h"

#include "Zombie.h"
#include "Projectile.h"
#include "History.h"

class Zombie;


int Lane::lane_counter = 0;


Lane::Lane()
{
	this->lane_number = Lane::lane_counter++;
	for (int i = 0; i < 9; i++) {
		vector<Entity*>* zombies_ = new vector<Entity*>;
		
		zombies.push_back(zombies_);
	}
	for (int i = 0; i < 9; i++) {
		projectiles.push_back(NULL);
	}
	for (int i = 0; i < 9; i++) {
		plants.push_back(NULL);
	}
}


Lane::~Lane()
{
}

void Lane::place_entity(Entity * ent, int position)
{
	if (position > 8) {
		ExceptionBadPosition ex;
		throw ex;
	}
	switch (ent->get_type()) {
	case type::PLANT:
		this->plants[position] = ent;
		break;
	case type::PLANT_CHERRY_BOMB:
		this->plants[position] = ent;
		break;
	case type::PLANT_PEASHOOTER:
		this->plants[position] = ent;
		break;
	case type::PROJECTILE:
		this->projectiles[position] = ent;
		break;
	case type::ZOMBIE:
		this->zombies[position]->push_back(ent);
		break;
	case type::ZOMBIE_POLE_VAULTING:
		this->zombies[position]->push_back(ent);
		break;
	case type::ZOMBIE_SUPER_ZOMBIE:
		this->zombies[position]->push_back(ent);
		break;
	case type::ZOMBIE_BUCKET_HEAD:
		this->zombies[position]->push_back(ent);
		break;
	}
	
}

void Lane::tick()
{

	this->no_of_ticks_total++;


	// ------------- plants tick -----------------
	if (this->no_of_plant_interval_ticks % 3 == 0) {
		for (int i = 0; i < this->get_plants().size(); i++) {
			Entity* entity = this->get_plants()[i];
			if (entity != NULL) {
				entity->tick();
			}
		}
	}
	this->no_of_plant_interval_ticks++;

	// ------------- zombies tick -----------------
	// only execute zombie ticks if it is time for zombies to move

	if (this->no_of_ticks_total % 40 == 0 || this->no_of_ticks_total % 30 == 0) {
		for (int i = 0; i < 9; i++) {

			vector<Entity*>* zombies_ = this->get_zombies()[i];// new vector<Entity*>;

			vector<Entity*> fast_zombies; // SUPER ZOMBIE, POLE VAULTING
			vector<Entity*> slow_zombies;
			for (int j = 0; j < zombies_->size(); j++) {
				Zombie* zombie = (Zombie*)((*zombies_)[j]);
				if (zombie != NULL) {
					if (zombie->get_type() == ZOMBIE_POLE_VAULTING || zombie->get_type() == ZOMBIE_SUPER_ZOMBIE) {
						fast_zombies.push_back(zombie);
					}
					else {
						slow_zombies.push_back(zombie);
					}
				}
			}

			
			if (this->no_of_ticks_total % 30 == 0) { // FAST ZOMBIES
				for (int j = 0; j < fast_zombies.size(); j++) {
					Zombie* zombie = (Zombie*)(fast_zombies[j]);
					zombie->move(this);
				}
			}
			else { // SLOW ZOMBIES
				for (int j = 0; j < slow_zombies.size(); j++) {
					Zombie* zombie = (Zombie*)(slow_zombies[j]);
					zombie->move(this);
				}
			}
			

			// (ALL) zombies move once every 5 seconds
			if (this->no_of_ticks_total % 50 == 0) {
				vector<Entity*>* zombies_ = this->get_zombies()[i];// new vector<Entity*>;
				for (int j = 0; j < zombies_->size(); j++) {
					Zombie* zombie = (Zombie*)((*zombies_)[j]);
					if (zombie != NULL) {
						zombie->move(this);
					}
				}
			}


		}
	}


	// ------------- projectiles tick -----------------
	for (int i = 8; i >= 0; i--) {
		Entity* proj = this->projectiles[i];
		if (proj != NULL) {

			proj->tick();
			if (proj != NULL) {
				((Projectile*)proj)->set_ticked(true);
			}
			
		}
	}

	for (int i = 0; i < this->projectiles.size(); i++) {
		Entity* proj = this->projectiles[i];
		if (proj != NULL) {
			((Projectile*)proj)->set_ticked(false);
		}

	}

	
	// History::debug("Plants have ticked");
	// History::debug_lane(this);

	
	// check for dead plants
	for (int i = 0; i < this->get_plants().size(); i++) {
		Entity* entity = this->get_plants()[i];
		if (entity != NULL) {
			if (entity->get_hp() <= 0) {
				this->get_plants()[i] = NULL;
			}
		}
	}

	// check for dead zombies
	for (int i = 0; i < 9; i++) {
		vector<Entity*>* zombies_ = this->get_zombies()[i];// new vector<Entity*>;
		for (int j = 0; j < zombies_->size(); j++) {
			// Zombie* zombie = (Zombie*)((*zombies_)[j]);
			Entity* entity = (*zombies_)[j];
			if (entity != NULL) {
				if (entity->get_hp() <= 0) {
					// (*zombies_)[j] = NULL;
					// (*this->get_zombies()[i])[j] = NULL;
					kill_zombie(entity);
				}
			}
		}
	}
}

int Lane::get_lane_number()
{
	return this->lane_number;
}
