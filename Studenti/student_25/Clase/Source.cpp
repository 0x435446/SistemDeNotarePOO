#include "ManagerJoc.h"
#include "Log.h"
#include "Exceptie.h"

#include <iostream>

int main()
{
	Log::logare("Deschidere aplicatie.");

	try
	{
		ManagerJoc& manager = ManagerJoc::getManager();

		manager.logare();
		manager.joaca();
	}
	catch (Exceptie & e)
	{
		system("cls");
		std::cout << e.mesaj << std::endl;
		Log::logare(e.mesaj);
		system("pause");
	}

	return 0;
}