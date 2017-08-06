#include "CrashBreak.h"


Vector2 CrashBreak::Encounter(Location loc, int radius , Vector2 speed)
{
	/*
	if (( loc.y == (GetSurfaceH() - radius)) && loc.x <= GetRightSideX() && loc.x >= GetLeftSideX())
	{
		speed.y = -speed.y;
	}
	return speed;
	*/

	//the check is been made before calling encounter
	//speed.y = abs(speed.y);				//when changed with minus the ball kept going forward sometimes
	if (loc.x>=GetRightSideX() || loc.x<=GetLeftSideX())
	{
		speed.x = -speed.x;
	}
	if (loc.x <= GetRightSideX() && loc.x >= GetLeftSideX())
	{
		speed.y = -speed.y;
	}
	return speed;
}



vector<CrashBreak*>* CrashBreak::generateBreaks(int amount)
{
	vector<CrashBreak*> *vec = new vector<CrashBreak*>;
	vector<CrashBreak*>* temp;
	CrashBreak* tempB;
	int hight = 20;

	while (amount > 0)
	{
		if (amount > Crash::MaxBreaksInRow)
		{
			temp = generateBreaksRow(Crash::MaxBreaksInRow, hight);
			amount -= Crash::MaxBreaksInRow;
		}
		else
		{
			temp = generateBreaksRow(amount, hight);
			amount = 0;
		}

		while (!temp->empty())
		{
			tempB = temp->back();
			temp->pop_back();
			vec->push_back(tempB);
		}
		delete temp;
		hight += SpaceBetweenBreaksHight + CrashBreakHeight;
	}
	return vec;

}


/*
generate row of crash breaks
*/
vector<CrashBreak*>* CrashBreak::generateBreaksRow(int amount, int hight)
{
	int currentWidth = 0;
	int extraEndLineSpace = 0;
	vector<CrashBreak*>* vec = new vector<CrashBreak*>;
	CrashBreak* temp;
	Location loc(0,hight + CrashBreakHeight/2);
	srand(time(NULL));

	if (amount > Crash::MaxBreaksInRow)
		amount = Crash::MaxBreaksInRow;

	currentWidth = amount* (SpaceBetweenBreaksWidth + CrashBreakWidth) + SpaceBetweenBreaksWidth;
	extraEndLineSpace = (Graphics::ScreenWidth - currentWidth) / 2;

	loc.setX(extraEndLineSpace + CrashBreakWidth/2);
	for (int i = 0; i < amount; i++)
	{
		loc.x += SpaceBetweenBreaksWidth;
		temp = new CrashBreak(Colors::cArray[rand()%8], loc);
		
		vec->push_back(temp);
		loc.x += CrashBreakWidth;
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

/*
void CrashBreak::MakeMap()
{
	CrashBreak::mapEnum[0] = Colors::White;
	CrashBreak::mapEnum[1] = Colors::Black;
	CrashBreak::mapEnum[2] = Colors::Gray;
	CrashBreak::mapEnum[3] = Colors::LightGray;
	CrashBreak::mapEnum[4] = Colors::Red;
	CrashBreak::mapEnum[5] = Colors::Green;
	CrashBreak::mapEnum[6] = Colors::Blue;
	CrashBreak::mapEnum[7] = Colors::Yellow;
	CrashBreak::mapEnum[8] = Colors::Cyan;
	CrashBreak::mapEnum[9] = Colors::Magenta;
} */
