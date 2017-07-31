#pragma once

#include "Shape.h"
#include "Bar.h"
#include <cmath>


class Ball : public Shape
{
private:
	int _radius;		//the radius of the ball
	Location speed;		//the speed of the ball. Location is like Vector2 

public:
	Ball(int r,Color c, Location loc,int s);
	virtual void DrawShape(Graphics & gfx);		//Draw the ball to the screen
	void BallMovement();						//moves the ball
	void Bounce(Bar* b);					//the ball bounce from the bar 
};