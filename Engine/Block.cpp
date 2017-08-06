#include "Block.h"

Block::Block(Color c, Location l, int w, int h)
	:
	Shape(c, l),
	_width(w),
	_hight(h)
{
}

void Block::DrawShape(Graphics & gfx)
//Draw a block to the screen
{
	/*
	for (int i = _location.x - (_width/2); i < _location.x + (_width/2); i++)
	{
		for (int j = _location.y - (_hight/2); j < _location.y + (_hight/2); j++)
		{
			gfx.PutPixel(i, j, _color);
		}
	}
	*/
	gfx.DrawRect(_location, _width, _hight, _color);

}
int Block::GetSurfaceH()
{
	return _location.y - (_hight / 2);
}

int Block::GetSurfaceB()
{
	return _location.y + (_hight / 2);
}

int Block::GetRightSideX()
{
	return _location.x + (_width / 2);
}

int Block::GetLeftSideX()
{
	return _location.x - (_width / 2);
}