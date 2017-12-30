//
//  libraries.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 30/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef libraries_h
#define libraries_h

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

#endif /* libraries_h */
