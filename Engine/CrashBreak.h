#pragma once

#include "Block.h"
#include <time.h>
#include <stdlib.h>

class CrashBreak : public Block
{
public:
	CrashBreak(Color c, Location l) 
		: Block(c, l, CrashBreakWidth, CrashBreakHeight),
		lives(NumLives)
	{}
	virtual Vector2 encounter(Location loc, int radius, Vector2 speed);
	static vector<CrashBreak*>* generateBreaks(int amount);
	static vector<CrashBreak*>* generateBreaksRow(int amount, int hight);
	

	static constexpr int CrashBreakWidth = 60;
	static constexpr int CrashBreakHeight = 15;
	static constexpr int SpaceBetweenBreaksWidth = 15;
	static constexpr int SpaceBetweenBreaksHight = 5;

	bool IsAlive();
	
	//static void MakeMap();
	void GotHit();
	//static map<int, Color> mapEnum;
	
private:
	int lives;
	static constexpr int NumLives = 1;
	
	

};


namespace Crash
{
	/*
	return the number of breaks that enter to the screen
	*/
	static constexpr int maxBreaksInRow()
	{
		int currentWidth = CrashBreak::CrashBreakWidth + 2 * CrashBreak::SpaceBetweenBreaksWidth;
		int breaksNum = 1;
		while ((currentWidth + CrashBreak::CrashBreakWidth + CrashBreak::SpaceBetweenBreaksWidth) <= Graphics::ScreenWidth)
		{
			breaksNum++;
			currentWidth += CrashBreak::CrashBreakWidth + CrashBreak::SpaceBetweenBreaksWidth;
		}

		return breaksNum;
	}

	static constexpr int MaxBreaksInRow = maxBreaksInRow();

}