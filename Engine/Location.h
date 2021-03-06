#pragma once
#include <cmath>
class Location
{
public:
	int x;	//x axis
	int y;	//y axis

	Location(int _x,int _y) : x(_x),y(_y) {}
	float Distance(Location loc) const;					//the distance between two Locations
	float Distance(int _x, int _y) const;				//the distance between two Locations
	void add(int deltaX,int deltaY);			//adds to the x and y
	void add(Location loc);						//adds to the x and y
	int getX() { return x; }					//returns x
	int getY() { return y; }					//returns y
	void setX(int _x) { x = _x; }				//set x
	void setY(int _y) { y = _y; }				//set y
};