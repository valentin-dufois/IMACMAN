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
}

//The main loop
void Core::main()
{
	int startTime, elapsedTime;

	while(GameObj->isRunning())
	{
		////////////////////////////////
		//The main loop

		//Actions
		//GameObj->gameEngine->doActionsOfAllScenes();

		startTime = SDL_GetTicks();

		/*Clear the screen*/
		glClear(GL_COLOR_BUFFER_BIT);
		SDL_GL_SwapWindow(GameObj->mainWindow);

		/*elapsedTime = SDL_GetTicks() - startTime;
		if(elapsedTime < 16.6f)
		{
			SDL_Delay(16.6f - elapsedTime);
		}*/

		std::cin.get();


		//Render
		//GameObj->renderEngine->render();

		//
		/////////////////////////////////
	}

	//End of game, clear everything
}
