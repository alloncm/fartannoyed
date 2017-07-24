#pragma once


#include "Block.h"
#include "Keyboard.h"

class Bar : Block
{
public:
	Bar(Color c,Location l,int w,int h,int s);
	int GetSurfaceH();
	int GetRightSideX();
	int GetLeftSideX();
	void MoveBar(int m);
private:
	int _speed;
};