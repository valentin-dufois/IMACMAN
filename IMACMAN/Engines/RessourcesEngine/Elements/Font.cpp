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
	//FT_Set_Char_Size(m_face, 0, m_size * 64, 0, SDL::getWindowDPI());
	FT_Set_Pixel_Sizes(m_face, 0, m_size);
}

FontFace Font::genFontFace()
{
	m_fontFace.size = m_size;

	//Disable GL Alignement
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	//Store all ASCII chars
	for(uint c = 0; c < 128; ++c)
	{
		m_fontFace.chars.push_back(genFontCharacter(c));
	}

	//Re-Enable GL Alignement
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

	return m_fontFace;
}

Mesh * Font::genCaption(const std::string &caption)
{
	//Gather informations for rendering
	uint textureWidth = 0;
	uint textureHeight = m_fontFace.size;

	for(char c : caption)
	{
		textureWidth += m_fontFace.chars[c].advance;
	}

	FontCharacter * lastChar = &m_fontFace.chars[caption[caption.size()-1]];
	textureWidth -= lastChar->advance;
	textureWidth += lastChar->bearing.x + lastChar->size.x;

	//Load shader program
	ShaderProgram program("triangle.vs.glsl", "textRenderer.fs.glsl");

	//generate the frameBuffer & texture
	GLuint frameBuffer;
	GLuint texture;
	prepareTexture(textureWidth, textureHeight, frameBuffer, texture);

	//Bind framebuffer
	glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
	glClear(GL_COLOR_BUFFER_BIT);

	//Fit to buffer
	GameObj->renderEngine->setProjection2D(textureWidth, textureHeight);

	Mesh * charMesh;
	uint advanceX = 0;
	FontCharacter fChar;

	for(char c : caption)
	{
		fChar = m_fontFace.chars[c];

		charMesh = GameObj->ressourcesEngine->gen2DTile(
			advanceX + fChar.bearing.x,
			fChar.size.y,
			fChar.size.x,
			fChar.size.y);

		std::cout << textureHeight << " : " << fChar.size.y << std::endl;

		charMesh->setProgram(&program);
		charMesh->setTexture(fChar.texture);
		charMesh->generate();
		charMesh->getCursor()->scale(1, -1, 1);

		/////////////////
		check_gl_error();
		/////////////////

		//Render char
		GameObj->renderEngine->render(charMesh, charMesh->getCursor());

		/////////////////
		check_gl_error();
		/////////////////

		//advance
		advanceX += fChar.advance;

		delete charMesh;
	}
	//GameObj->renderEngine->getCameraCursor()->reset();

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glViewport(0, 0, 800, 600);

	///////////////
	
	Mesh * mesh = GameObj->ressourcesEngine->gen2DTile(0, 0, textureWidth, textureHeight);
	mesh->setTexture(texture);
	mesh->applyCursor();

	return mesh;
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

	glTexImage2D(GL_TEXTURE_2D,
				 0,
				 GL_RED,
				 m_face->glyph->bitmap.width,
				 m_face->glyph->bitmap.rows,
				 0,
				 GL_RED,
				 GL_UNSIGNED_BYTE,
				 m_face->glyph->bitmap.buffer);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	/*Set texture options*/
	glBindTexture(GL_TEXTURE_2D, 0); /*Leave the texture*/

	character.texture = texture;

	character.size.x = m_face->glyph->bitmap.width;
	character.size.y = m_face->glyph->bitmap.rows;

	character.bearing.x = m_face->glyph->bitmap_left / 64.f;
	character.bearing.y = m_face->glyph->bitmap_top / 64.f;

	character.advance = m_face->glyph->advance.x / 64.f;

	return character;
}

bool Font::prepareTexture(const uint &width, const uint &height, GLuint &frameBuffer, GLuint &texture)
{
	GLuint format = GL_RGBA;

	//generate the frameBuffer
	glGenFramebuffers(1, &frameBuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);

	//Generate and bind the texture
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	// Give an empty image to OpenGL ( the last "0" )
	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, 0);

	//filters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	//Link texture to framebuffer
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);

	GLenum DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};
	glDrawBuffers(1, DrawBuffers);

	////
	check_gl_error();

	if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		return false;

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	return true;
}

GLuint Font::genTile(const GLuint &textureID)
{
	///////////
	//CHAR TILE

	std::vector<Vertex> vertices;
	vertices.push_back(Vertex(glm::vec3(0, 0, 0), glm::vec2(0, 0)));
	vertices.push_back(Vertex(glm::vec3(1, 0, 0), glm::vec2(1, 0)));
	vertices.push_back(Vertex(glm::vec3(1, 1, 0), glm::vec2(1, 1)));

	vertices.push_back(Vertex(glm::vec3(0, 0, 0), glm::vec2(0, 0)));
	vertices.push_back(Vertex(glm::vec3(1, 1, 0), glm::vec2(1, 1)));
	vertices.push_back(Vertex(glm::vec3(0, 1, 0), glm::vec2(0, 1)));

	/////
	//VBO
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	/////////////////
	check_gl_error();
	/////////////////

	/////
	//VAO
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	const GLuint VERTEX_ATTR_POSITION = 1;
	const GLuint VERTEX_ATTR_UV = 4;
	glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
	glEnableVertexAttribArray(VERTEX_ATTR_UV);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(VERTEX_ATTR_UV, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)offsetof(Vertex, UV));
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	/////////////////
	check_gl_error();
	/////////////////

	return vao;
}

Font::~Font()
{
	FT_Done_Face(m_face);
}
