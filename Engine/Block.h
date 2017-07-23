#pragma once

#include "Shape.h"

class Block : public Shape
{
protected:
	int width;
	int hight;

public:
	Block();
	void interactWithBall();
};