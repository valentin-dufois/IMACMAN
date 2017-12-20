//
//  Image.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "Image.hpp"

//Getters
SDL_Surface* Image::getImage() const
{
  return m_image;
}

int Image::getImageSize() const
{
  return m_image->w * m_image->h;
}

//Setters
void Image::setImage(SDL_Surface* image)
{
  //Is image loaded ?
	if(!image) {
		throw std::runtime_error("There is no Image at this pointer.");
	}

	//Convert to RGBA surface
	SDL_Surface * formattedImage = SDL_ConvertSurfaceFormat(image, SDL_PIXELFORMAT_RGBA8888, 0);
	if(!formattedImage) {
		SDL_FreeSurface(image);
		throw std::runtime_error("Could not formate the image.");
	}

  m_image = formattedImage;
}

//Utils
