/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Ball.h"
#include "Bar.h"
#include "CrashBreak.h"
#include <vector>

using namespace std;

#define BALL_RADIUS 12
#define BALL_LOCATOIN {Graphics::ScreenWidth/2,Graphics::ScreenHeight/2}
#define BALL_START_SPEED 4
//#define BALL_INCREMENT_PERCENTS 1.1

#define BAR_LOCATOIN { 400,500 }
#define BAR_WIDTH 200
#define BAR_HIGHT 12
#define BAR_SPEED 6

#define NUM_OF_CRASH_BREAKS 55

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	~Game();
	void Go();

	/*************************/
	/*    User Functions     */
	bool fall();
	void lostGame();
	void Drawlives();
	/*************************/


private:
	void ComposeFrame();
	void UpdateModel();

	/********************************/
	/*  User Functions              */
	int GetKeyboardInputBar();
	/********************************/


private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	Ball ball;		//the ball 
	vector<CrashBreak*>* breaks;
	Bar* bar;		//the abr the player controls
	int lives;

	bool isAlive;

	bool reLive;		//bool to indicate whether the ball needs to be reinit after fell to the floor
						//to init press space
	/********************************/
};