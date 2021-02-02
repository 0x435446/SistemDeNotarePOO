#pragma once
#include "Resources.h"
#include "Buzunar.h"
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;
class Sun :public Resources
{
public:
	int Da_Sau_Nu;
	Sun(int Resources,int da_sau_nu);
	int Give_Resource()override;
};