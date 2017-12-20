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

	//Specifies texture parameters
	GLenum imgTexType = GL_TEXTURE_2D, mode = GL_RGBA;


	//Init and bind an OpenGL texture
	GLuint texture;

	glGenTextures(1, &texture);
	glBindTexture(imgTexType, texture);

	//Insert data in the 2D texture
	glTexImage2D(imgTexType, 0, mode, imgSurface->w, imgSurface->h, 0, mode, GL_FLOAT, imgSurface->pixels);
	//Define preset for graphic card
	glTexParameteri(imgTexType, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(imgTexType, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Unbinding of the texture
	glBindTexture(imgTexType, 0);

	//Access SDL pixels values and get colors and AlphaChannel
	std::vector<SDL_Color> rawData = getColorPixels(imgSurface);

	//Create a New Image Asset
	Image* image = new Image(0, IMAGE, imgSurface->w, imgSurface->h, rawData);

	// clean up the SDL_Surfaces
	SDL_FreeSurface(formattedSurface);
  SDL_FreeSurface(imgSurface);

	return image;
}

/**
 * Get the Color of each pixels in the SDL_Surface as an RGBA SDL_Color structure
 */
std::vector<SDL_Color> ImageImporter::getColorPixels(SDL_Surface* surface)
{
	SDL_LockSurface(surface);

	int bytesPerPixel = surface->format->BytesPerPixel;
	std::vector<SDL_Color> data;
	Uint8 *pixel;
	SDL_Color color;

	if (bytesPerPixel != 4) {
		throw std::runtime_error("Wrong type of Image. It's not RGBA");
	}

	// Extraction of the color data
	for(int y = 0; y < surface->h; ++y) {
		for(int x = 0; x < surface->w; ++x) {
			pixel = (Uint8 *)surface->pixels + y * surface->pitch + x * bytesPerPixel;
			SDL_GetRGBA(*(Uint32 *)pixel, surface->format, &color.r, &color.g, &color.b, &color.a);
			data.push_back(color);
		}
	}

	SDL_UnlockSurface(surface);
	return data;
}

ImageImporter::~ImageImporter()
{

}
