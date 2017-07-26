#pragma once

#include "Shape.h"
#include "Location.h"

class Block : public Shape
{
protected:
	int _width;
	int _hight;

public:
	Block(Color c,Location l,int w,int h);
	virtual void DrawShape(Graphics & gfx);
	int GetSurfaceH();
	int GetRightSideX();
	int GetLeftSideX();
	virtual Location encounter(Location loc, int radius, Location speed) = 0;
};