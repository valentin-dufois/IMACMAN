//
//  Font.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 28/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "Font.hpp"

Font::Font(FT_Face &face): Asset(FONT), m_face(face) {}

void Font::setHeight(const float &newSize)
{
	m_size = newSize;

	FT_Set_Char_Size(m_face, 0, m_size * 64, 0, SDL::getWindowDPI());
}

FontFace Font::genFontFace()
{
	FontFace fontFace;
	fontFace.size = m_size;

	//Disable GL Alignement
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	//Store all ASCII chars
	for(uint c = 0; c < 128; ++c)
	{
		fontFace.chars.push_back(genFontCharacter(c));
	}

	//Re-Enable GL Alignement
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

	return fontFace;
}

FontCharacter Font::genFontCharacter(char charID)
{
	GLuint texture;
	FontCharacter character;

	/*Load glyph*/
	FT_Load_Char(m_face, charID, FT_LOAD_RENDER);

	/*Generate texture with the glyph*/
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D,
				 0,
				 GL_INTENSITY,
				 m_face->glyph->bitmap.width,
				 m_face->glyph->bitmap.rows,
				 0,
				 GL_LUMINANCE,
				 GL_UNSIGNED_BYTE,
				 m_face->glyph->bitmap.buffer);

	/*Set texture options*/
	glBindTexture(GL_TEXTURE_2D, 0); /*Leave the texture*/

	character.texture = texture;

	character.size.x = m_face->glyph->bitmap.width;
	character.size.y = m_face->glyph->bitmap.rows;

	character.bearing.x = m_face->glyph->bitmap_left;
	character.bearing.y = m_face->glyph->bitmap_top;

	character.advance = (GLuint)m_face->glyph->advance.x;

	return character;
}

Font::~Font()
{
	FT_Done_Face(m_face);
}
