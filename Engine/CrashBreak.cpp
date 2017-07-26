#include "CrashBreak.h"


Location CrashBreak::encounter(Location loc, int radius , Location speed)
{
	if (( loc.y == (GetSurfaceH() - radius)) && loc.x <= GetRightSideX() && loc.x >= GetLeftSideX())
	{
		speed.y = -speed.y;
	}
	return speed;
}