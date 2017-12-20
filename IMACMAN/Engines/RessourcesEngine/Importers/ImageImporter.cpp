//
//  ImageImporter.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "../../../main.hpp"
#include "../Elements/Image.hpp"

Asset * ImageImporter::getAsset(std::string path)
{
	//Load image
	SDL_Surface * imgSurface = IMG_Load(path.c_str());

	//Is image loaded ?
	if(!imgSurface) {
		throw std::runtime_error("Could not load " + path + " : " + std::string(IMG_GetError()));
	}

	//Convert to RGBA surface
	SDL_Surface * formattedSurface = SDL_ConvertSurfaceFormat(imgSurface, SDL_PIXELFORMAT_RGBA8888, 0);
	if(!formattedSurface) {
		SDL_FreeSurface(imgSurface);
		throw std::runtime_error("Could not formate: "+ path);
	}

	//Create a New Image Asset
	Image* image = new Image(0, IMAGE, imgSurface);

	// clean up the SDL_Surfaces
	SDL_FreeSurface(formattedSurface);
  SDL_FreeSurface(imgSurface);

	return image;
}

void ImageImporter::bindTextureToOpengl(GLuint textureID, SDL_Surface* surface)
{
	//Specifies texture parameters
	GLenum imgTexType = GL_TEXTURE_2D, mode = GL_RGBA;
	//Init and bind an OpenGL texture
	glGenTextures(1, &textureID);
	glBindTexture(imgTexType, textureID);

	//Insert data in the 2D texture
	glTexImage2D(imgTexType, 0, mode, surface->w, surface->h, 0, mode, GL_FLOAT, surface->pixels);

	//Define preset for graphic card
	glTexParameteri(imgTexType, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(imgTexType, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Unbinding of the texture
	glBindTexture(imgTexType, 0);
}

ImageImporter::~ImageImporter()
{

}
