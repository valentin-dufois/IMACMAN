//
//  GameObject.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 21/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include "../main.hpp"

//Forward declarations
class GameEngine;
class RessourcesEngine;
class RenderEngine;
class Scene;

class GameObject
{
public:

	/**
	 Instancite the object as a Singleton
	 */
	static void instanciate();

	/**
	 * Engines
	 */
	GameEngine * gameEngine;
	RessourcesEngine * ressourceEngine;
	RenderEngine * renderEngine;

	/**
	 * The window, managed by SDL
	 */
	SDL_Window * mainWindow;

	/**
	 Tell if the app is currently running
	 Used by the main loop

	 @return true if running, false otherwise
	 */
	inline bool isRunning() const { return m_running; };

	
	/**
	 Add a new scene to the loop

	 @param scene The scene to add
	 */
	void addScene(Scene * scene);

	/**
	 Return all scene currently in loop

	 @return The scenes in a vector
	 */
	std::vector<Scene *> getScenes() const { return m_scenes; };

private:
	//Singleton
	GameObject() {};
	bool static m_instanciated;

	//Game states
	bool m_running = true;

	//Scenes
	std::vector<Scene *> m_scenes;

};

extern GameObject * GameObj;

#endif /* GameObject_hpp */
