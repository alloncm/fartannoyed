#pragma once

#include "Colors.h"
#include "Location.h"
#include "Graphics.h"

#define BALL_TOTAL_SPEED 4

class Shape
{
public:
	Shape(Color color, Location location) : _color(color), _location(location) {}
	virtual void DrawShape(Graphics & gfx) = 0;

protected:
	Color _color;
	Location _location;
};