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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	test0(1, 2.3),
	test1(2, 3.2)
{
}

void Game::Go()
{


	Vec2 test3 = test0 + test1;
	Vec2 test4 = test0 * 5;
	test0 += test1;
	test1 *= 3;



	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = tf.timeStamp();


	// only updates board when the game starts, isn't paused, and isn't over
	if (hasStarted && !paused && !brd.getGameOver()) {
		brd.update(wnd, dt);
	}
	else if (wnd.kbd.KeyIsPressed(VK_UP) || wnd.kbd.KeyIsPressed(VK_DOWN) || wnd.kbd.KeyIsPressed(VK_LEFT) || wnd.kbd.KeyIsPressed(VK_RIGHT)) {
			hasStarted = true;
	}
	// mechanism for pausing the game
	if (wnd.kbd.KeyIsPressed('P') && !pausedDown) {
		paused = !paused;
		pausedDown = true;
	}
	else if (!wnd.kbd.KeyIsPressed('P') && pausedDown) {
		pausedDown = false;
	}
	// mechanism for restarting the game
	if (brd.getGameOver() && wnd.kbd.KeyIsPressed(VK_RETURN) && !restartDown) {
		brd.reset();
		hasStarted = false;
		paused = false;
		restartDown = true;
		ComposeFrame();
	}
	else if (restartDown && !wnd.kbd.KeyIsPressed(VK_RETURN)) {
		restartDown = false;
	}



}

void Game::ComposeFrame()
{

	brd.drawBrd(gfx);

}
