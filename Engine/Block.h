#pragma once

#include "Shape.h"

class Block : public Shape
{
protected:
	int _width;
	int _hight;

public:
	Block(Color c,Location l,int w,int h);
	void interactWithBall();
	virtual void DrawShape(Graphics & gfx);
};