#include "ConsoleOutput.h"

class Interfata_LVL3 :
	public UserInterface::ConsoleOutput
{
private:
	UserInterface::ConsoleOutput conOut;

protected:
	void Layout_LVL3();

public:
	Interfata_LVL3();
	~Interfata_LVL3();

};