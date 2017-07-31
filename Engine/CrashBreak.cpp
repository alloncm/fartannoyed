#include "CrashBreak.h"


Location CrashBreak::encounter(Location loc, int radius , Location speed)
{
	if (( loc.y == (GetSurfaceH() - radius)) && loc.x <= GetRightSideX() && loc.x >= GetLeftSideX())
	{
		speed.y = -speed.y;
	}
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
		temp = new CrashBreak(Colors::Blue, l);
		vec->push_back(temp);
	}
	return vec;
}