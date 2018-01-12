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

class GameEngine
{
public:
	//Instanciate the GameEngine in the GameObj as a Singleton
	static void instanciate();

	//Free memory and set m_instanciated to null
	static void reset();

	//Catch new events then execute all scenes on the AppObj
	void executeScenes();
	void renderScenes();

	/**
	 Return the key struct
	 @return The keyboard structure
	 */
	inline keyboard getKeys() const { return m_keys; };
	inline void flushKeys() { m_keys = {}; };

	//Grid-relative Methods
	Grid * getGrid();
	void loadLevel(Level * level);

	void displayLevel();
	void displayInfo();

	void inGameChecks();

	void manageSpecialMode();

	inline Pacman * getPacman() { return m_pacman; };

	void deleteGrid()
	{
		std::cout << "delete grid" << std::endl;
		delete m_level;
	};
	
private:
	//Singleton
	static bool m_instanciated;
	GameEngine() = default;

	//Events
	keyboard m_keys;
	void parseEvents();

	//Attributs
	Grid * m_level;

	Pacman * m_pacman;

	Ghost * m_Blinky;
	Ghost * m_Pinky;
	Ghost * m_Inky;
	Ghost * m_Clyde;
	Fruit * m_fruit;
};

#endif /* GameEngine_hpp */
