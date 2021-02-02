#include "Entity.h"



Entity::Entity(type type_, Lane* lane) : type_(type_), lane(lane)
{
}


Entity::~Entity()
{
}

int Entity::get_position(Lane* lane)
{
	
	
		for (int i = 0; i < lane->get_plants().size(); i++) {
			Entity* entity = (Entity*)lane->get_plants()[i];
			if (entity == this) {
				return i;
			}

			vector<Entity*>* zombies = lane->get_zombies()[i];
			for (int j = 0; j < zombies->size(); j++) {
				Entity* zombie = (*zombies)[j];
				if (zombie == this) {
					return i;
				}
			}
			

			Entity* entity3 = (Entity*)lane->get_projectiles()[i];
			if (entity3 == this) {
				return i;
			}
		}

		// TODO: entity not found exception
		return -1;

	
}
