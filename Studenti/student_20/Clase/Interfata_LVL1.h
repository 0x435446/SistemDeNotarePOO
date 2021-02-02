#include "ConsoleOutput.h"

class Interfata_LVL1:
	public UserInterface::ConsoleOutput
{
private:
	UserInterface::ConsoleOutput conOut;

protected:
	void Layout_LVL1();

public:
	Interfata_LVL1();
	~Interfata_LVL1();

};
