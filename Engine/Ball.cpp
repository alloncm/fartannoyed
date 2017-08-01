#include "Ball.h"

Ball::Ball(int r, Color c, Location loc,int s) 
	:
	Shape(c, loc),
	speed(s,s),
	_radius(r)
{
	
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
//moves the ball depends on the walls
{
	_location.add(speed);
	
	if (_location.x + _radius >= Graphics::ScreenWidth) //right wall
	{
		speed.x =-speed.x;
		_location.x = Graphics::ScreenWidth - _radius - 1;
	}
	else if(_location.x - _radius<= 0) //left wall
	{
		speed.x = -speed.x;
		_location.x = 0 + _radius;
	}
	if (_location.y + _radius >= Graphics::ScreenHeight) //floor
	{
		speed.y = -speed.y;
		_location.y = Graphics::ScreenHeight - _radius - 1;
	}
	else if (_location.y - _radius <= 0) //ceiling
	{
		speed.y = -speed.y;
		_location.y = 0 + _radius;
	}

	
}


//the ball bounce from the block. in encounter the angle is being calculated
bool Ball::Bounce(Block* b)
{
	/*
	if ((((_location.y <= (b->GetSurfaceH() - _radius))&& _location.y+speed.y>= (b->GetSurfaceH() - _radius)) && _location.x <= b->GetRightSideX() && _location.x >= b->GetLeftSideX()))
		speed = b->encounter(_location,_radius,speed);
	*/
	//bounce from the block
	//better 
	if (ColideWithBlock(b))
	{
		speed = b->encounter(_location, _radius, speed);
		return true;
	}
	return false;
}

bool Ball::ColideWithBlock(Block * b)
//still needs to improve it by not checking the inside of the block
//checks if the ball collides with the block
{
	for (int i = b->GetLeftSideX(); i < b->GetRightSideX(); i++)
	{
		for (int j = b->GetSurfaceH(); j < b->GetSurfaceB(); j++)
		{
			if (_location.Distance(i, j) <= _radius)
			{
				return true;
			}
		}
	}
	return false;
}
