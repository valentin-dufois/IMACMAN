//
//  GameObject.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 21/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

class GameObject
{
public:
	/*
	RessourceEngine * ressourceEngine;
	GameEngine * gameEngine;
	RenderEngine * renderEngine;
	*/

	//The window, managed by SDL
	SDL_Window * mainWindow;

	//Getters
	bool isRunning();

private:
	//Game states
	bool m_running = true;
};

extern GameObject * GameObj;

#endif /* GameObject_hpp */
