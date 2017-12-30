//
//  main.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#pragma once

////////////////////
// Standard includes
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include <map>
#include <vector>


///////////////////
// Needed libraries
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#ifdef __APPLE__
#    include <SDL2_image/SDL_image.h>
#else
#    include <SDL2/SDL_image.h>
#endif

#include <ft2build.h>
#include FT_FREETYPE_H

#include <glm/glm.hpp>


/////////////////
//UUID generation
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>


////////////////////////
// IMACMAN global object
#define FRAMERATE 1000/60


///////////////////
// IMACMAN Includes
#include "Core/GameObject.hpp"
#include "Core/Core.hpp"
#include "Core/Igniter.hpp"

#include "Utils/SDL.hpp"
#include "Utils/ShaderProgram.hpp"
#include "Utils/Selector/Selector.hpp"

#include "Engines/GameEngine/Player.hpp"
#include "Engines/GameEngine/GameEngine.hpp"
#include "Engines/RessourcesEngine/RessourcesEngine.hpp"
#include "Engines/RenderEngine/RenderEngine.hpp"

#include "Scenes/Scene.hpp"

//Create type for unsigned short ints
using usint = unsigned short int;
