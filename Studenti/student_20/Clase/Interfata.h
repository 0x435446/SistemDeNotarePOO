#include <iostream>
#include <vector>

#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Utilizator.h"
#include "Interfata_LVL1.h"
#include "Interfata_LVL2.h"
#include "Interfata_LVL3.h"



class Interfata :
	public UserInterface::ConsoleInput,
	public UserInterface::ConsoleOutput,
	protected Interfata_LVL1,
	protected Interfata_LVL2,
	protected Interfata_LVL3,
	protected Utilizator
{
protected:
	int Dificultate;
	void Draw_Table();
	

	UserInterface::ConsoleOutput conOut;
	UserInterface::ConsoleInput conIn;

public:
	void GetName();
	void GetDifficulty();
	void SetDifficulty(int Grad);
	void ChooseLayout();
	void Clscr();


	Interfata();
	~Interfata();

};
