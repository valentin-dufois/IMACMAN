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

	//Specifies texture parameters
	GLenum imgTexType = GL_TEXTURE_2D;
	GLuint texture;
	GLenum mode = GL_RGB;

	if(imgSurface->format->BytesPerPixel == 4) {
	    mode = GL_RGBA;
	}

	//Init and bind an OpenGL texture
	glGenTextures(1, &texture);
	glBindTexture(imgTexType, texture);

	//Insert data in the 2D texture
	glTexImage2D(imgTexType, 0, mode, imgSurface->w, imgSurface->h, 0, mode, GL_FLOAT, imgSurface->pixels);
	//Define preset for graphic card
	glTexParameteri(imgTexType, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(imgTexType, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Debinding of the texture
	glBindTexture(imgTexType, 0);

	//Create a New Image Asset
	Image* image = Image(0, IMAGE, imgSurface->w, imgSurface->h, (imgSurface->w * imgSurface->h));

	// clean up the SDL_Surface
  SDL_FreeSurface(imgSurface);

	return image;
}

ImageImporter::~ImageImporter()
{

}
