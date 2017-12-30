//
//  Font.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 28/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef Font_hpp
#define Font_hpp

//Forward Declaration
class Asset;

#include "Asset.hpp"
#include "Utils/SDL.hpp"

#include <iostream>


//////////////////
//Font structures
struct FontCharacter
{
	GLuint texture;
	glm::vec2 size;
	glm::vec2 bearing;
	GLuint advance;
};

struct FontFace
{
	float size;
	std::vector<FontCharacter> chars;
};

/////////////
//Font class
class Font : public Asset
{
public:
	Font(FT_Face &face);

	/**
	 Set the font height.
	 Takes the screen DPI in account

	 @param newSize The font new size
	 */
	void setHeight(const float &newSize);


	/**
	 Generate and return the FontFace

	 @return The FontFace
	 */
	FontFace genFontFace();

	~Font();

private:

	//The face
	FT_Face m_face;
	float m_size;

	FontCharacter genFontCharacter(char charID);
};

#endif /* Font_hpp */
