#include "Location.h"

int Location::Distance(Location loc)
{
	int _x = this->x - loc.x;
	int _y = this->y - loc.y;
	return int(sqrt((_x*_x) + (_y*_y)));
}

int Location::Distance(int _x, int _y)
{
	return Distance({ _x,_y });
}

void Location::add(int a, int b)
{
	x += a;
	y += b;
}

void Location::add(Location loc)
{
	this->add(loc.x, loc.y);
}
