//
//  GameEngine.cpp
//  IMACMAN
//
//  Created by Laurie Greinert on 22/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "../../main.hpp"

bool GameEngine::m_instanciated = false;

/**
 * Instanciate the game engine as a Singleton
 */
void GameEngine::instanciate()
{
	if(m_instanciated)
		return;
	
	GameObj->gameEngine = new GameEngine();
	
	m_instanciated = true;
}

GameEngine::GameEngine()
{
	
}
