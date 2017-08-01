#pragma once

#include "Block.h"

class CrashBreak : public Block
{
public:
	CrashBreak(Color c, Location l) 
		: Block(c, l, CrashBreakWidth, CrashBreakHeight),
		lives(NumLives)
	{}
	virtual Location encounter(Location loc, int radius, Location speed);
	static vector<CrashBreak*>* generateBreaks(int amount);
	static constexpr int CrashBreakWidth = 30;
	static constexpr int CrashBreakHeight = 10;
	bool IsAlive();
	void GotHit();
private:
	int lives;
	static constexpr int NumLives = 1;

};