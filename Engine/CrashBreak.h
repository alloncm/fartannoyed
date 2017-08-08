#pragma once

#include "Block.h"
#include <time.h>
#include <stdlib.h>

class CrashBreak : public Block
{
public:
	CrashBreak(Color c, Location l) 
		: Block(c, l, CrashBreakWidth, CrashBreakHeight, L"CrashBreakBamp.wav"),
		lives(NumLives)
	{}
	virtual Vector2 Encounter(Location loc, int radius, Vector2 speed);
	static vector<CrashBreak*>* generateBreaks(int amount);
	static vector<CrashBreak*>* generateBreaksRow(int amount, int hight);
	

	static constexpr int CrashBreakWidth = 62;
	static constexpr int CrashBreakHeight = 17;
	static constexpr int SpaceBetweenBreaksWidth = 7;
	static constexpr int SpaceBetweenBreaksHight = 5;
	static constexpr int SpaceFromTop = 50;
	static constexpr float BallIncrementPercents = 1.02;

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
	static int maxBreaksInRow()
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

	static const int MaxBreaksInRow = maxBreaksInRow();

}