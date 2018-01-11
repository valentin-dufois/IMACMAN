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
	GLuint colorMode = GL_BGR;
	if(m_surface->format->BytesPerPixel == 4)
		colorMode = GL_BGRA;

	std::cout << "format : " << m_surface->format->BytesPerPixel << std::endl;

	glGenTextures(1, &m_textureID);
	glBindTexture(GL_TEXTURE_2D, m_textureID);

	glTexImage2D(GL_TEXTURE_2D,
				 0,
				 GL_RGB,
				 m_width,
				 m_height,
				 0,
				 colorMode,
				 GL_UNSIGNED_BYTE,
				 m_surface->pixels);
	check_gl_error();

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, 0); /*Leave the texture*/
}
