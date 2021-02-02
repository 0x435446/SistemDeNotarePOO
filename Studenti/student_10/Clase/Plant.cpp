#include "Plant.h"




Plant::Plant(type type_, Lane* lane) : Entity(type_, lane)
{
	this->type_ = type_;
	switch (type_) {
	case PLANT_PEASHOOTER:
		this->hp = 100;
		this->damage = 50;
		break;
	case PLANT_WALLNUT:
		this->hp = 300;
		this->damage = 0;
		break;
	case PLANT_CHERRY_BOMB:
		this->hp = 500;
		this->damage = CHERRY_BOMB_DAMAGE;
		break;
	}
}


Plant::~Plant()
{
}

void Plant::tick()
{
	int position_of_current_plant = this->get_position(this->lane);
	if (this->type_ == PLANT_PEASHOOTER) {
		
		Projectile* projectile = new Projectile(this->lane, this->damage);

		this->lane->get_projectiles()[position_of_current_plant] = projectile;
	}
	else if (this->type_ == PLANT_CHERRY_BOMB) {
		// TODO: get all lanes
		vector<Entity*> zombies_to_take_damage = this->lane->get_zombies_positions_for_cb_damage(position_of_current_plant);
		for (int i = 0; i < zombies_to_take_damage.size(); i++) {
			if (zombies_to_take_damage[i] != NULL) {
				zombies_to_take_damage[i]->set_hp(zombies_to_take_damage[i]->get_hp() - this->damage);
				Level::player_score++;
			}
			else {
				// zombie is dead
			}
		}
	}
}

string Plant::draw()
{
	switch (this->type_) {
	case PLANT_PEASHOOTER:
		return "P";
		break;
	case PLANT_CHERRY_BOMB: 
		return "C";
		break;
	}
	return "N";
}
