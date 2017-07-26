#pragma once
#include <cmath>
class Location
{
public:
	int x;
	int y;

	Location(int _x,int _y) : x(_x),y(_y) {}
	int Distance(Location loc);//the distance between two Locations
	void add(int deltaX,int deltaY);
	void add(Location loc);
	int getX() { return x; }
	int getY() { return y; }
	void setX(int _x) { x = _x; }
	void setY(int _y) { y = _y; }
};