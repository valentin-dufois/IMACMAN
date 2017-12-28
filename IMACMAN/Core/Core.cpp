//
//  Core.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 21/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "../main.hpp"
#include <SDL2/SDL_image.h>

//Ignite the different aspects of the game
void Core::ignite()
{
	Igniter igniter = Igniter();

	igniter.igniteGameObject();
	igniter.igniteSDL();
	igniter.igniteOpenGL();

	//Init random generator
	srand((uint)time(NULL));
}

//The main loop
void Core::main()
{
	std::chrono::high_resolution_clock::time_point start, end;

	while(GameObj->isRunning())
	{
		////////////////////////////////
		//The main loop

		start = std::chrono::high_resolution_clock::now();

		//Actions
		//GameObj->gameEngine->doActionsOfAllScenes();

		/*Clear the screen*/
		glClear(GL_COLOR_BUFFER_BIT);

		//Render
		//GameObj->renderEngine->render();

		SDL_GL_SwapWindow(GameObj->mainWindow);

		end = std::chrono::high_resolution_clock::now();

		//Tempo
		Core::tempo(start, end);

		//
		/////////////////////////////////
	}

	//End of game, clear everything
}

void Core::tempo(std::chrono::high_resolution_clock::time_point start, std::chrono::high_resolution_clock::time_point end)
{
	std::chrono::milliseconds elapsed, toWait;

	elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	if(elapsed.count() < FRAMERATE)
	{
		toWait = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::milliseconds(FRAMERATE) - elapsed);
		std::this_thread::sleep_for(toWait);
	}
}

