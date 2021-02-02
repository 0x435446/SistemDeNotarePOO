#pragma once
#include "Entity.h"
#include "ConsoleOutput.h"
#include "ConsoleInput.h"
#include <string> 
class Zona :
	public Entity
{
private:
	int x, y;
	bool filled;
	Entity *caracter;
public:
	Zona():x(0),y(0){}
	Zona(int a,int b):x(a),y(b){}
	void draw();
	~Zona();
	void set_position(int a,int b);
	int get_x() {
		return x;
	}
	void update(std::string action) {
		if (filled)
			caracter->update(action);
	}
	int get_y() { return y; }
	bool selected(std::string);
	bool is_filled();
	void set_free();

	
	void set_filed();
	void set_empty();
	void draw_zona_resurse();
	void draw_zona_plante();
	void draw_zona_scor_sun();
};

