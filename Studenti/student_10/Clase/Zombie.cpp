#include "Zombie.h"
#include <algorithm>


Zombie::Zombie(type type_, Lane* lane) : Entity(type_, lane)
{
	this->type_ = type_;
	if (this->type_ == type::ZOMBIE) {
		this->set_hp(300);
	}
	else if (this->type_ == type::ZOMBIE_POLE_VAULTING) {
		this->set_hp(1000);
	}
	else if (this->type_ == type::ZOMBIE_SUPER_ZOMBIE) {
		this->set_hp(2000);
	}
	else if (this->type_ == type::ZOMBIE_BUCKET_HEAD) {
		this->set_hp(2000);
	}
}


Zombie::~Zombie()
{
}



bool Zombie::shouldMove(Lane* lane)
{
	int position_of_current_zombie = this->get_position(lane);
	Entity* last_plant = lane->get_last_plant();
	int position_of_last_plant = last_plant->get_position(lane);
	if (position_of_last_plant == position_of_current_zombie - 1) {
		// TODO: if zombie is of type pollvaulting => return true
		if (( this->type_ == ZOMBIE_POLE_VAULTING && this->has_vaulted == false) || (this->type_ == ZOMBIE_SUPER_ZOMBIE && this->has_vaulted == false)) {
			History::debug("ZOMBIE VAULTED FROM POSITION: " + to_string(position_of_current_zombie));
			this->has_vaulted = true;
			return true;
		}
		return false;
	}
	return true;

}

void Zombie::move(Lane * lane)
{
	if (shouldMove(lane)) {
		int position_of_current_zombie = this->get_position(lane);
		if (position_of_current_zombie == 0) {
			// TODO: end game message
			if(this->get_hp() > 0){
			}
		}
		else {
			
			vector<Entity*>* current_position = lane->get_zombies()[position_of_current_zombie];
			
			int index = -1;
			for (int i = 0; i < current_position->size(); i++) {
				Zombie* element = (Zombie*)((*current_position)[i]);
				if (element == this) {
					index = i;
					break;
				}
			}
			
			// TODO: if the zombie has a plant ahead and it is not a poll vaulting zombie => do not move
			if (this->get_type() == type::ZOMBIE_POLE_VAULTING || this->get_type() == type::ZOMBIE_SUPER_ZOMBIE) {
				// --------- move ------------
				current_position->erase(current_position->begin() + index);
				vector<Entity*>* next_position = lane->get_zombies()[position_of_current_zombie - 1];
				next_position->push_back(this);
				// --------- /move ------------
			}else{
				vector<Entity*>& plants_from_current_lane = lane->get_plants();
				Entity* plant_before = plants_from_current_lane[position_of_current_zombie - 1];
				if (plant_before != NULL) { // TODO: check if plant is dead
					// do not move
				}
				else {
					// --------- move ------------
					current_position->erase(current_position->begin() + index);
					vector<Entity*>* next_position = lane->get_zombies()[position_of_current_zombie - 1];
					next_position->push_back(this);
					// --------- /move ------------
				}
			}

			

			
		}
	}
}

void Zombie::tick()
{
	cout << "Zombie ticking" << endl;
	if (this->frozent_duration > 0) {
		this->speed = 1;
		this->frozent_duration--;
	}
	else {
		this->speed = 2;
	}
}

string Zombie::draw()
{
	if (this->type_ == ZOMBIE_BUCKET_HEAD) {
		return "BH";
	}

	if (this->type_ == ZOMBIE_POLE_VAULTING) {
		return "PV";
	}

	if (this->type_ == ZOMBIE_SUPER_ZOMBIE) {
		return "S+";
	}

	if (this->type_ == ZOMBIE) {
		return "ZZ";
	}


	return "Z";
	
}
