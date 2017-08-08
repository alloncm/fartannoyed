#include "Location.h"

float Location::Distance(Location loc) const
{
	int _x = this->x - loc.x;
	int _y = this->y - loc.y;
	return (sqrt((_x*_x) + (_y*_y)));
}

float Location::Distance(int _x, int _y) const
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
