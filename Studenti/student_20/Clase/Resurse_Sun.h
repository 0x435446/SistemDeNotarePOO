#include "Resurse.h"
class Resurse_Sun:
	public Resurse
{
public:
	const float SpawnTime = 2;
	float ReduceTime = 0;
	void Add_Sun();
	void Sub_Sun(int Valoare);
	void Add_Time(int Valoare);
	void Sub_Time(int Valoare);
	float GetTime();
	
	Resurse_Sun();
	~Resurse_Sun();

};
