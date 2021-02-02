#include "DoubleClick.h"



DoubleClick::DoubleClick(const std::string& action)
{
	char *p, sep[] = "  : \.(),;";
	char *dup = _strdup(action.c_str());
	p = strtok(dup, sep);
	int ok = 0;
	while (p)
	{
		if (isNumber(p) == true && ok == 0)
		{
			ok = 1;
			y = atoi(p);
		}
		else if (isNumber(p) == true && ok == 1)
		{
			x = atoi(p);
			break;
		}
		p = strtok(NULL, sep);
	}
	free(dup);
}

int DoubleClick::returnX()
{
	return x;
}

int DoubleClick::returnY()
{
	return y;
}

bool DoubleClick::isNumber(char *s)
{
	if (isdigit(s[0]))
	{
		return true;
	}
	else return false;
}
