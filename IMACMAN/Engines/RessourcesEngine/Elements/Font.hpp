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
#include "Utils/ShaderProgram.hpp"
#include "Engines/RenderEngine/RenderEngine.hpp"

#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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
	 Return the height of the font

	 @return the font height
	 */
	inline float getHeight() const { return m_size; };


	/**
	 Generate and return the FontFace

	 @return The FontFace
	 */
	FontFace generate();

	/**
	 Generate a 2D tile with the caption as its texture
	 THe return Mesh is raw, it as not been generated and as no program attached

	 @param caption The text to display
	 @return The tile in a mesh
	 */
	Mesh * genCaption(const std::string &caption);

	~Font();

private:

	//The face
	FT_Face m_face;
	float m_size;

	FontFace m_fontFace;

	/**
	 Generate and store in OpenGL the specified character

	 @param charID The character to render
	 @return The character infos
	 */
	FontCharacter genFontCharacter(char charID);

	bool prepareTexture(const uint &width, const uint &height, GLuint &frameBuffer, GLuint &texture);

	GLuint genTile(const GLuint &textureID);

	void cleanFontFace();
};

#endif /* Font_hpp */
