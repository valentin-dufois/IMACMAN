//
//  Igniter.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 21/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef Igniter_hpp
#define Igniter_hpp

#include "libraries.hpp"
#include "Core/GameObject.hpp"

#include "Engines/GameEngine/GameEngine.hpp"
#include "Engines/RessourcesEngine/RessourcesEngine.hpp"
#include "Engines/RenderEngine/RenderEngine.hpp"

class Igniter
{
public:
	void igniteGameObject();
	void igniteSDL();
	void igniteOpenGL();
	void igniteEngines();
};

#endif /* Igniter_hpp */
