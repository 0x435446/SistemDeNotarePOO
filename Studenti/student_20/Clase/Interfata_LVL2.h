#include "ConsoleOutput.h"

class Interfata_LVL2 :
	public UserInterface::ConsoleOutput
{
private:
	UserInterface::ConsoleOutput conOut;

protected:
	void Layout_LVL2();

public:
	Interfata_LVL2();
	~Interfata_LVL2();

};
