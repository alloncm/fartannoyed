#include "Bar.h"

Bar::Bar(Color c, Location l, int w, int h,int s)
	:
	Block(c,l,w,h),
	_speed(s)
{
}

int Bar::GetSurfaceH()
{
	return _location.y - (_hight / 2);
}

int Bar::GetRightSideX()
{
	return _location.x + (_width / 2);
}

int Bar::GetLeftSideX()
{
	return _location.x - (_width / 2);
}

void Bar::MoveBar(int m)
{
	if (m == 2&& _location.x + (_width / 2) + _speed < Graphics::ScreenWidth)
	{
		_location.x+=_speed;
	}
	
	if (m == 1&& _location.x - (_width / 2) - _speed >0)
	{
		_location.x-=_speed;
	}
	
}
