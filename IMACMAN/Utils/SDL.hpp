//
//  SDL.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 28/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef SDL_hpp
#define SDL_hpp

#include "../main.hpp"

namespace SDL
{
	/**
	 Get the window index on the SDL

	 @return The index
	 */
	int getWindowIndex();

	/**
	 Return the DPI of the screen the game window is on

	 @return The DPI
	 */
	float getWindowDPI();
}

#endif /* SDL_hpp */
