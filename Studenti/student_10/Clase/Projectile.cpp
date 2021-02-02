#include "Projectile.h"
#include "History.h"


Projectile::Projectile(Lane* lane, int damage)  : Entity(type::PROJECTILE, lane), damage(damage)
{
	this->id = Projectile::projectile_counter++;
}


Projectile::~Projectile()
{
}

void Projectile::tick()
{
	Lane* lane = this->lane;

	
	
	if (this->has_ticked) {
		return;
	}
	int projectile_position = this->get_position(lane);
	if (projectile_position < 8) {

		vector<Entity*> zombies_in_front = this->lane->get_zombies_at_position(projectile_position);
		// attack zombies one by one


		Entity* first_zombie = NULL;
		if (zombies_in_front.size() > 0) {

			for (int i = 0; i < zombies_in_front.size(); i++) {
				if (zombies_in_front[i] != NULL) {
					first_zombie = zombies_in_front[i];
					break;
				}
			}
		}
		if(first_zombie != NULL){
			History::debug("\nZOMBIE hit by projectile!!\n");
			if (zombies_in_front[0] != NULL) {
				zombies_in_front[0]->set_hp(zombies_in_front[0]->get_hp() - this->damage);

				if (zombies_in_front[0]->get_hp() < 0) {
					lane->kill_zombie(zombies_in_front[0]);
				}
			}
			lane->get_projectiles()[projectile_position] = NULL; // 'delete' the current projectile
		}
		else {
			// the projectile has not hit anything, it just moves along
			lane->get_projectiles()[projectile_position + 1] = this;
			lane->get_projectiles()[projectile_position] = NULL;
		}

	}
	else {
		lane->get_projectiles()[8] = NULL;
	}
	

}

string Projectile::draw()
{
	return "-";
}

int Projectile::get_id()
{
	return this->id;
}


int Projectile::projectile_counter = 0;