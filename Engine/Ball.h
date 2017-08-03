#pragma once

#include "Shape.h"
#include "Bar.h"
#include <cmath>




class Ball : public Shape
{
private:
	int _radius;		//the radius of the ball
	Vector2 speed;		//the speed of the ball.  

public:
	Ball(int r,Color c, Location loc,float s);
	virtual void DrawShape(Graphics & gfx);		//Draw the ball to the screen
	void BallMovement();						//moves the ball
	bool Bounce(Block* b);						//the ball bounce from the block if hits return true
	bool ColideWithBlock(Block* b);				//checks if the ball touches the block it recives

};