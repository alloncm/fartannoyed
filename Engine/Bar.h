#pragma once

#include "Block.h"
#include "Keyboard.h"



class Bar : public Block
{
public:
	Bar(Color c,Location l,int width,int hight,int s);
	void MoveBar(int m);													//moves the bar
	//virtual Location encounter(Location loc, int radius, Location speed);	//encounter the ball to the right position
	virtual Vector2 encounter(Location loc, int radius, Vector2 speed);			//another version of encounter for the bar im checking
private:
	int _speed;																//the speed of the bar movement
};