//
//  Image.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef Image_hpp
#define Image_hpp

#include "Asset.hpp"

class Image : public Asset
{
public:

	Image(SDL_Surface * imageSurface);

	inline SDL_Surface * getSurface() const { return m_surface; };

	inline GLuint getTextureID() const { return m_textureID; };

	~Image();

private:

	SDL_Surface * m_surface;
	GLuint m_textureID;

    //Image infos
    uint m_width;
    uint m_height;

	/**
	 Return the image format to use with openGL

	 @param image The image to analyse
	 @return The color format in the image
	 */
	GLenum getImageFormat(SDL_Surface * image);
};

#endif /* Image_hpp */
