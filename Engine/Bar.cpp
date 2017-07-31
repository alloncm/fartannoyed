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
		break;

	case 2:
		if (_location.x + (_width / 2) + _speed < Graphics::ScreenWidth)
		{
			_location.x += _speed;
		}
		break;

	default:
		//do nothing
		break;
	}
}



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
	
	if (speed.y >= -1)
		speed.y = -1;
	return speed;
	
}
