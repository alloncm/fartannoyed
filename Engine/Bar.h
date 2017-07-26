#pragma once


#include "Block.h"
#include "Keyboard.h"

class Bar : public Block
{
public:
	Bar(Color c,Location l,int width,int hight,int s);
	void MoveBar(int m);
	Location encounter(Location loc, int radius, Location speed);
private:
	int _speed;
};