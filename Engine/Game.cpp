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
	ball (25, Colors::Green, { 100,100 }, 7)
{
		bar = new Bar(Colors::Blue,{ 400,500 }, 300, 15, 6);
		breaks = CrashBreak::generateBreaks(30);
}

Game::~Game()
{
	CrashBreak* temp;

	delete bar;
	for (int i = 0; i < !breaks->empty; i++)
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
	ball.BallMovement();
	ball.Bounce(bar);
	bar->MoveBar(GetKeyboardInputBar());
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
}

