#pragma once

#include "Shape.h"
#include "Location.h"

class Block : public Shape
{
protected:
	int _width;		//the width of the block	
	int _hight;		//the height of the block

public:
	Block(Color c,Location l,int w,int h);
	virtual void DrawShape(Graphics & gfx);										//draw the block to the screen
	int GetSurfaceH();															//returns the Y location of the up surface of the block 
	int GetRightSideX();														//return the right side X of the block
	int GetLeftSideX();															//returns the left side X of the Block
	virtual Location encounter(Location loc, int radius, Location speed) = 0;	// return the speed the ball at after the encounter
};