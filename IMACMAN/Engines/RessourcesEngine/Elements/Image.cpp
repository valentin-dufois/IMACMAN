//
//  Image.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "Image.hpp"

Image::Image(SDL_Surface * imageSurface):
	Asset(IMAGE),
	m_surface(imageSurface),
	m_width(imageSurface->w),
	m_height(imageSurface->h)
{
	glGenTextures(1, &m_textureID);
	glBindTexture(GL_TEXTURE_2D, m_textureID);

	glTexImage2D(GL_TEXTURE_2D,
				 0,
				 GL_RGBA,
				 m_width,
				 m_height,
				 0,
				 getImageFormat(m_surface),
				 GL_UNSIGNED_BYTE,
				 m_surface->pixels);
	check_gl_error();

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, 0); /*Leave the texture*/
}

GLenum Image::getImageFormat(SDL_Surface * image)
{
	switch(image->format->BytesPerPixel)
	{
		case 1:
			return GL_RED;
			break;
		case 3:
			return GL_BGR;
			break;
		case 4:
			return GL_BGRA;
			break;
		default:
			return 0;
	}
}

Image::~Image()
{
	SDL_FreeSurface(m_surface);
	glDeleteTextures(1, &m_textureID);
}
