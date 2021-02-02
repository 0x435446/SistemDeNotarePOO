#include "Combat.h"

#define NR_OF_ZOMBIES	5
using namespace std::chrono;

Combat* Combat::instance = nullptr;
Combat* Combat::GetInstance() {
	if (instance == nullptr)
		instance = new Combat;

	return instance;
}

Combat::Combat()
{
	
}


Combat::~Combat()
{
}

void Combat::create_zombie()
{
	Zombies* z = new Zombie();
	zombie_vector.push_back(z);
	z->print_entity();
	//z->move();
}

bool Combat::fight(Click& click)
{
	UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	

	auto begin = steady_clock::now();
	static int zombie_count = NR_OF_ZOMBIES;
	std::vector<Plant*> plants_vector = click.get_vector();
	std::vector<Plant*>::iterator it_p;
	std::vector<Zombies*>::iterator it_z;

		auto end = steady_clock::now();
		if (zombie_count > 0) {
			create_zombie();
			zombie_count--;
		}

		for (it_z = zombie_vector.begin()/*, it_p=plants_vector.begin()*/; 
			it_z != zombie_vector.end() /*&& it_p!=plants_vector.end()*/; (it_z)++ /*, (it_p)++*/) {
			
			while (duration_cast<seconds>(end - begin).count() < 3) {
				std::string action = conIn.getUserActions();
				if (action.find("Mouse", 0) != std::string::npos) {
					conOut(41, 2) << action;
					if (action.find("click", 0) != std::string::npos)
						click.get_click(conIn.get_y(), conIn.get_x());
				}
				end = steady_clock::now();

			}
			
			//(*it_p)->shoot_projectiles();
			(*it_z)->move();
			if ((*it_z)->get_y() < 39)
				return false;
			
			//begin = steady_clock::now();
		}

		
	return true;
}
