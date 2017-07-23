#pragma once

#include "Colors.h"
#include "Location.h"
#include "Graphics.h"

class Shape
{
public:
	Shape(Color color, Location location) : _color(color), _location(location) {}
	virtual void DrawShape(Graphics & gfx) = 0;

protected:
	Color _color;
	Location _location;
};