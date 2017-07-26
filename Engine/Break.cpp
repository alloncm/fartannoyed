#include "Block.h"

int Block::GetSurfaceH()
{
	return _location.y - (_hight / 2);
}

int Block::GetRightSideX()
{
	return _location.x + (_width / 2);
}

int Block::GetLeftSideX()
{
	return _location.x - (_width / 2);
}