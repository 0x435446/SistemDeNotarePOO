#pragma once
#include "Entity.h"
#include "Peashooter.h"
#include "Sunflower.h"
#include "ConsoleOutput.h"
#include "ConsoleInput.h"
class Parcela : public Entity
{
private:
	int x, y;
	bool filled;
	
public:
	Plant *plant;
	int getx();
	int gety();
	void freee();
	void setfilled();
	void setfree();
	bool isfilled();
	void plant_Peashooter();
	void plant_Sunflower();
	Parcela();
	~Parcela();
	Parcela(int, int);
	void draw();
	void draw_select();
	void delet_selected();
	void draw_price();
	bool selected(std::string action);
	void uppdate(std::string);
	
};

