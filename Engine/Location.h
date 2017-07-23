#pragma once
#include <cmath>
struct Location
{
	int x;
	int y;
	Location(int _x,int _y) : x(_x),y(_y) {}
	int Distance(Location loc);//the distance between two Locations
	void add(int a,int b);
	void add(Location loc);
};