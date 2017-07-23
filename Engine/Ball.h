#pragma once

#include "Shape.h"

class Ball : public Shape
{
private:
	int _radius;
	Location speed;

public:
	Ball(int r,Color c, Location loc,int s);
	virtual void DrawShape(Graphics & gfx);
	void BallMovement();
};