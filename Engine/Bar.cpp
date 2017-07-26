#include "Bar.h"

Bar::Bar(Color c, Location l, int w, int h,int s)
	:
	Block(c,l,w,h),
	_speed(s)
{
}



void Bar::MoveBar(int choice)
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
