//
//  SDL.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 28/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "SDL.hpp"

namespace SDL
{
	int getWindowIndex()
	{
		return SDL_GetWindowDisplayIndex(GameObj->mainWindow);
	}

	float getWindowDPI()
	{
		float DPI;

		SDL_GetDisplayDPI(getWindowIndex(), &DPI, nullptr, nullptr);

		return DPI;
	}
}
