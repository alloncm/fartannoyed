#include "CrashBreak.h"


Vector2 CrashBreak::encounter(Location loc, int radius , Vector2 speed)
{
	/*
	if (( loc.y == (GetSurfaceH() - radius)) && loc.x <= GetRightSideX() && loc.x >= GetLeftSideX())
	{
		speed.y = -speed.y;
	}
	return speed;
	*/

	//the check is been made before calling encounter
	speed.y = abs(speed.y);				//when changed with minus the ball kept going forward sometimes
	return speed;
}



vector<CrashBreak*>* CrashBreak::generateBreaks(int amount)
{
	vector<CrashBreak*> *vec = new vector<CrashBreak*>;
	CrashBreak* temp;
	Location l(20, 20);
	for (int i = 0; i < amount; i++)
	{
		// need to generate the locations of the breaks
		if (l.x + CrashBreakWidth >= Graphics::ScreenWidth)		//if the next break is going to be outside the screen go in
		{
			l.y += CrashBreakHeight + 1;	//plus one for the space between the blocks
			l.x = 20;
		}
		if (l.y + CrashBreakHeight <= Graphics::ScreenHeight)		//if the next break is in the screen go in
		{
			l.x++;		//plus one for the space between blocks
			temp = new CrashBreak(Colors::Red, l);
			vec->push_back(temp);
			l.x += CrashBreakWidth;
		}
		
	}
	return vec;
}

bool CrashBreak::IsAlive()
{
	return lives > 0;
}

void CrashBreak::GotHit()
{
	lives--;
}
