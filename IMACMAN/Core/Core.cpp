//
//  Core.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 21/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "../main.hpp"

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
	while(GameObj->isRunning())
	{
		////////////////////////////////
		//The main loop

		//Actions




		//Render

		//
		/////////////////////////////////
	}

	//End of game, clear everything
}
