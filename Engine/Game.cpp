/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball (BALL_RADIUS, Colors::Green,BALL_LOCATOIN , BALL_SPEED),
	lives(3)
{
		bar = new Bar(Colors::Blue,BAR_LOCATOIN , BAR_WIDTH, BAR_HIGHT, BAR_SPEED);
		breaks = CrashBreak::generateBreaks(NUM_OF_CRASH_BREAKS);
}

Game::~Game()
{
	CrashBreak* temp;

	delete bar;
	for (int i = 0; i < breaks->size(); i++)
	{
		temp = breaks->back();
		breaks->pop_back();
		delete temp;
	}
	delete breaks;
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!ball.BallMovement())
	{
		if (fall())
		{
			ball.setLocation(BALL_LOCATOIN);
			ball.setSpeed(BALL_SPEED);
		}
		else
			lostGame();
	}
	ball.Bounce(bar);
	bar->MoveBar(GetKeyboardInputBar());
	for (int i = 0; i < breaks->size(); i++)
	{
		if (breaks->at(i)->IsAlive() && ball.Bounce(breaks->at(i)))
		{
				breaks->at(i)->GotHit();
		}
		
	}

}

int Game::GetKeyboardInputBar()
{
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		return 1;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		return 2;
	}
}



void Game::ComposeFrame()
{
	ball.DrawShape(gfx);
	bar->DrawShape(gfx);
	for (int i = 0; i < breaks->size(); i++)
	{
		if (breaks->at(i)->IsAlive())
		{
			breaks->at(i)->DrawShape(gfx);
		}
	}
}


/*
descend the lives by 1 and return true if still alive, or false if lost
*/
bool Game::fall()
{
	return --lives;
}


/*
take care of ending the game
*/
void Game::lostGame()
{
	//show message to user

	this->~Game();
}