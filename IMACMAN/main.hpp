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
#include <map>


///////////////////
// Needed libraries
#ifdef __APPLE__
#    include <OpenGL/gl.h>
#else
#    include <GL/gl.h>
#endif

#include <SDL2/SDL.h>
#include <SDL2_Image/SDL_image.h>


///////////////////
// IMACMAN global object

///////////////////
// IMACMAN Includes
#include "Core/GameObject.hpp"
#include "Core/Core.hpp"
#include "Core/Igniter.hpp"

#include "Engines/RessourcesEngine/RessourcesEngine.hpp"

