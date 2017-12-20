//
//  GameObject.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 21/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

//Forward declarations
class GameEngine;
class RessourcesEngine;
class RenderEngine;
class Scene;

#include "../main.hpp"

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
	inline void addScene(Scene * scene) { m_scenes.push_back(scene); };

	/**
	 Return all scene currently in loop

	 @return The scenes in a vector
	 */
	std::vector<Scene *> getScenes() const { return m_scenes; };

	/**
	 Remove the given scene from the loop

	 - important: The function does NOT destruct the scene. It only removes its reference.
	 The scene must be removed afterward

	 @param scene The scene to remove
	 */
	void removeScene(Scene * scene);

	/**
	 Return a newly generated UUID

	 @return UUID
	 */
	inline boost::uuids::uuid getUUID() { return m_uuidGenerator(); };

private:
	//Singleton
	GameObject() {};
	bool static m_instanciated;

	//Game states
	bool m_running = true;

	//Scenes
	std::vector<Scene *> m_scenes;

	//UUID
	boost::uuids::random_generator m_uuidGenerator;

};

extern GameObject * GameObj;

#endif /* GameObject_hpp */
