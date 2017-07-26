#pragma once

#include "Block.h"

class CrashBreak : public Block
{
public:
	CrashBreak(Color c, Location l, int w, int h) : Block(c, l, w, h) {}
	Location encounter(Location loc, int radius, Location speed);

};