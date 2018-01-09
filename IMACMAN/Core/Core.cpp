//
//  Core.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 21/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "Core.hpp"

//Ignite the different aspects of the game
void Core::ignite(std::string appPath)
{
	Igniter igniter = Igniter();

	igniter.igniteGameObject(appPath);
	igniter.igniteSDL(800, 600);
	igniter.igniteOpenGL();

	GameObj->renderEngine->initRender();

	//Init random generator
	srand((uint)time(NULL));
}

//The main loop
void Core::main()
{
	std::chrono::high_resolution_clock::time_point start, end;

	//Load the first scene
	sceneTest002::load();

	while(GameObj->isRunning())
	{
		////////////////////////////////
		//The main loop

		start = std::chrono::high_resolution_clock::now();

		//Actions
		GameObj->gameEngine->executeScenes();

		//Render
		GameObj->gameEngine->renderScenes();

		end = std::chrono::high_resolution_clock::now();

		//Tempo
		Core::tempo(start, end);

		//
		/////////////////////////////////
	}

	//End of game, clear everything
	GameObj->gameEngine->reset();
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

