#include "Bar.h"

Bar::Bar(Color c, Location l, int w, int h,int s)
	:
	Block(c,l,w,h),
	_speed(s)
{
}



void Bar::MoveBar(int choice)
//the bar moves depends on input recived from the user only right and left. 
//1 for left 2 for right
{
	switch (choice)
	{
	case 1:
		if (_location.x - (_width / 2) - _speed >0)
		{
			_location.x -= _speed;
		}
		else
		{
			_location.x = 0 + _width / 2;
		}
		break;

	case 2:
		if (_location.x + (_width / 2) + _speed < Graphics::ScreenWidth)
		{
			_location.x += _speed;
		}
		else
		{
			_location.x = Graphics::ScreenWidth - _width / 2;
		}
		break;

	default:
		//do nothing
		break;
	}
}


/*
Location Bar::encounter(Location loc, int radius, Location speed)
{
		int disFromRight = GetLeftSideX() + _width - loc.x;

		//if (speed.x >= 0) // ball comes from left
		//{
		if (disFromRight < (_width / 2)) // at the right side of the bar
		{
			double disByPercent = disFromRight / ((double)_width / 2);
			speed.x = BALL_TOTAL_SPEED * (1 - disByPercent);
			speed.y = BALL_TOTAL_SPEED * -1 * disByPercent;

		}
		else // at the left side of the bar
		{
			double disByPercent = (_width - disFromRight) / ((double)_width / 2);
			speed.x = BALL_TOTAL_SPEED * -1 * (1 - disByPercent);
			speed.y = BALL_TOTAL_SPEED * -1 * disByPercent;
		}
		//}
		/*else // ball from right
		{
			if (disFromRight < (_width / 2)) // at the right side of the bar
			{
				double disByPercent = disFromRight / (_width / 2);
				speed.x = BALL_TOTAL_SPEED *  (1 - disByPercent);
				speed.y = BALL_TOTAL_SPEED * disByPercent;
			}
			else // at the left side of the bar
			{
				double disByPercent = (_width - disFromRight) / (_width / 2);
				speed.x = BALL_TOTAL_SPEED * -1 * (1 - disByPercent);
				speed.y = BALL_TOTAL_SPEED * disByPercent;
			}
		} */
	/*
	if (speed.y >= -1)
		speed.y = -1;
	return speed;
	
}
*/
Vector2 Bar::Encounter(Location loc, int radius, Vector2 speed)
{
	const float TotalSpeed = speed.Length();
	const float PI = 3.14159265f;

	if (loc.x>_location.x)
	{
		int disFromRight = GetRightSideX() - loc.x;
		float angle = atan((float(disFromRight) / (float(_width / 2) - disFromRight)));
		speed.x = TotalSpeed*cos(angle);
		speed.y = -TotalSpeed*sin(angle);
		while (speed.y >= -1.0f)
		{
			angle += 0.1f;
			speed.x = TotalSpeed*cos(angle);
			speed.y = -TotalSpeed*sin(angle);
		}
	}
	else
	{
		int disFromLeft = loc.x - GetLeftSideX();
		float angle = atan(  (float(_width / 2) - disFromLeft)/ (float(disFromLeft))) + PI/2;
		speed.x = TotalSpeed*cos(angle);
		speed.y = -TotalSpeed*sin(angle);
		while (speed.y >= -1.0f)
		{
			angle -= 0.1f;
			speed.x = TotalSpeed*cos(angle);
			speed.y = -TotalSpeed*sin(angle);
		}
	}
	return speed;
}
