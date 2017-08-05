#pragma once

#include "Colors.h"
#include "Location.h"
#include "Graphics.h"
#include <vector>

#define BALL_TOTAL_SPEED 10

using namespace std;

class Shape
{
public:
	Shape(Color color, Location location) : _color(color), _location(location) {}
	virtual void DrawShape(Graphics & gfx) = 0;		//virtual function to draw shape to the screen
	void setLocation(Location loc) { _location = loc; }

protected:
	Color _color;			//color of the shape
	Location _location;		//the location of the shape
};