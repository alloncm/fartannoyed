#include "Ball.h"

Ball::Ball(int r, Color c, Location loc,int s) 
	:
	Shape(c, loc),
	speed(s,s)
{
	_radius = r;
}

void Ball::DrawShape(Graphics & gfx)
//Draw a ball to the Screen
{
	int x = _location.x - _radius;
	int y = _location.y - _radius;
	Location loc(x,y);
	
	for (int i = 0; i < _radius*2+1; i++)
	{
		
		for (int j = 0; j < _radius*2+1; j++)
		{
			if (loc.Distance(_location) <= _radius)
			{
				gfx.PutPixel(loc.x, loc.y, _color);
			}
			loc.y++;
		}
		loc.x++;
		loc.y = _location.y - _radius;
		
	}
}

void Ball::BallMovement()
{
	
	
	if (_location.x + _radius >= Graphics::ScreenWidth-speed.x) //right wall
	{
		speed.x =-speed.x;
	}
	else if(_location.x - _radius <= 0) //left wall
	{
		speed.x = -speed.x;
	}
	if (_location.y + _radius >= Graphics::ScreenHeight-speed.y) //ceiling
	{
		speed.y = -speed.y;
	}
	else if (_location.y - _radius <= 0) //floor
	{
		// lost a ball
		speed.y = -speed.y;
	}

	_location.add(speed);
}

void Ball::BounceFromBlock(Block* b)
{
	speed = b->encounter(_location,_radius,speed);

	
}
