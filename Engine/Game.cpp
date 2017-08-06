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
	ball(BALL_RADIUS, Colors::Green, BALL_LOCATOIN, 0),
	lives(3),
	isAlive(true),
	reLive(true)
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
			ball.setLocation({Graphics::ScreenWidth/2,Graphics::ScreenHeight/2});
			ball.SetSpeed(0);
			reLive = true;
		}
		else
			lostGame();
	}
	//allow the player to decide when to continue the game after falling by pressing space
	if (reLive)
	{
 		if (wnd.kbd.KeyIsPressed(VK_SPACE))
		{
			ball.SetSpeedY(sqrt(pow(BALL_SPEED,2)+pow(BALL_SPEED,2)));
			reLive = false;
		}
		
	}
	ball.Bounce(bar);												//makes the ball bounce from the bar
	bar->MoveBar(GetKeyboardInputBar());							//movement of the bar
	//check for the breaks if they got hit
	//if they are unalive them
	for (int i = 0; i < breaks->size(); i++)
	{

		if (breaks->at(i)->IsAlive())
		{
			if (ball.Bounce(breaks->at(i)))
			{
				breaks->at(i)->GotHit();
			}
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
	if (isAlive)
	{
		ball.DrawShape(gfx);
	}
	
	bar->DrawShape(gfx);
	for (int i = 0; i < breaks->size(); i++)
	{
		if (breaks->at(i)->IsAlive())
		{
			breaks->at(i)->DrawShape(gfx);
		}
	}

	Drawlives();
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

	isAlive = false;
}

void Game::Drawlives()
//draw the lives left for the player to the screen
{
	int x = 20;
	int y = Graphics::ScreenHeight - 20;
	int width = 7;
	int height = 15;
	int space = 10;

	for (int i = 0; i < lives; i++)
	{
		gfx.DrawRect({ x,y }, width, height, Colors::White);
		x += space;
	}
}
