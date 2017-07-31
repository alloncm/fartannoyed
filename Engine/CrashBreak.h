#pragma once

#include "Block.h"

class CrashBreak : public Block
{
public:
	CrashBreak(Color c, Location l) : Block(c, l, 30, 5) {}
	Location encounter(Location loc, int radius, Location speed);
	static vector<CrashBreak*>* generateBreaks(int amount);

};