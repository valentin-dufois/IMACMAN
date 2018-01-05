//
//  GameEngine.hpp
//  IMACMAN
//
//  Created by Laurie Greinert on 22/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef GameEngine_hpp
#define GameEngine_hpp

#include "Grid.hpp"
#include "Core/GameObject.hpp"
#include "Engines/RessourcesEngine/RessourcesEngine.hpp"
#include "Scenes/Scene.hpp"

#include <vector>

struct keyboard
{
	bool A = false;
	bool B = false;
	bool C = false;
	bool D = false;
	bool E = false;
	bool F = false;
	bool G = false;
	bool H = false;
	bool I = false;
	bool J = false;
	bool K = false;
	bool L = false;
	bool M = false;
	bool N = false;
	bool O = false;
	bool P = false;
	bool Q = false;
	bool R = false;
	bool S = false;
	bool T = false;
	bool U = false;
	bool V = false;
	bool W = false;
	bool X = false;
	bool Y = false;
	bool Z = false;
	bool UP = false;
	bool DOWN = false;
	bool LEFT = false;
	bool RIGHT = false;
	bool ESC = false;
	bool BACKSPACE = false;
	bool ENTER = false;
};

class GameEngine{
public:
	/**
	 Instanciate the GameEngine in the GameObj as a Singleton
	 */
	static void instanciate();

	/**
	 Catch new events then execute all scenes on the AppObj
	 */
	void executeScenes();

	/**
	 Render all scenes
	 */
	void renderScenes();

	/**
	 Return the key struct
	 @return The keyboard structure
	 */
	inline keyboard getKeys() const { return m_keys; };

	/**
	 Reset all keys to false.
	 */
	inline void flushKeys() { m_keys = {}; };

	/**
	 Init the level
	 */
	void loadLevel(Level * level);
	void displayLevel();
	Grid * getGrid();

	void updateSpecialCountDowns();
	
private:
	//Singleton
	static bool m_instanciated;
	GameEngine();

	//Attributs
	Grid m_level;
	Pacman * m_pacman;
	Ghost * m_Blinky;
	Ghost * m_Pinky;
	Ghost * m_Inky;
	Ghost * m_Clyde;
	
	//Events
	keyboard m_keys;
	/**
	 Parse, update and store all events
	 */
	void parseEvents();


};

#endif /* GameEngine_hpp */
