//
//  RenderEngine.cpp
//  IMACMAN
//
//  Created by Gaëlle Calmels on 19/12/2017.
//  Copyright © 2017 Gaëlle Calmels. All rights reserved.
//

#include "RenderEngine.hpp"

bool RenderEngine::m_instanciated = false;

/**
 * Instanciate the engine as a Singleton
 */
void RenderEngine::instanciate()
{
	if(m_instanciated)
		return;

	GameObj->renderEngine = new RenderEngine();

	m_instanciated = true;
}

/**
 * Private constructor
 */
RenderEngine::RenderEngine(GLuint gridVBO, GLuint pacmanVBO, std::vector<GLuint> ghostsVBO)
{
	m_gridVBO = gridVBO;
	m_pacmanVBO = pacmanVBO;
	//initVBO(GL_ARRAY_BUFFER, &m_pacmanVBO, GRID_MANAGER);

	m_ghostsVBO = ghostsVBO;
	//initVBO(GL_ARRAY_BUFFER, &m_ghostsVBO[0] , GRID_MANAGER);
	//initVBO(GL_ARRAY_BUFFER, &m_ghostsVBO[1], GRID_MANAGER);
	//initVBO(GL_ARRAY_BUFFER, &m_ghostsVBO[2], GRID_MANAGER);
}

void loadPlateBoard()
{

}

void loadGrid()
{

}

void RenderEngine::initVBO(GLenum bufferType, GLuint * index, managerType type, std::vector<Vertex> * vertices, uint nbOfVertex, GLuint nbOfVBO)
{
	//Get Manager for the future VBO
	Manager * manager = getManager(type);
	//Generate VBO
	glGenBuffers(nbOfVBO, index);
	//Bind the VBO to OpenGL
	glBindBuffer(bufferType, *index);
	//Fill the VBO with data (Factory pattern)
	manager->fillVBO(nbOfVertex, vertices);
	//Unbind the VBO from OpenGL
	glBindBuffer(bufferType, 0);
}

void RenderEngine::initVAO()
{
	/*
	if(m_vbo == 0)
		return; //No VBO, no VAO!

	//Bind VAO
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	//Define vertice properties array hooks
	const GLuint VERTEX_ATTR_POSITION = 1;
	const GLuint VERTEX_ATTR_COLOR = 2;
	const GLuint VERTEX_ATTR_UV = 3;
	glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
	glEnableVertexAttribArray(VERTEX_ATTR_COLOR);
	glEnableVertexAttribArray(VERTEX_ATTR_UV);

	//Bind mesh VBO
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

	//Specify vertice properties positions
	glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(VERTEX_ATTR_COLOR, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *) offsetof(Vertex, color));
	glVertexAttribPointer(VERTEX_ATTR_UV, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *) offsetof(Vertex, UV));

	//Unbind everything
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);*/
}

Manager * RenderEngine::getManager(managerType type)
{
	Manager * manager = nullptr;

	switch (type)
	{
		case GRID_MANAGER:
			manager = new GridManager();
			break;
		case PACMAN_MANAGER:
			manager = new PacmanManager();
			break;
		case GHOST_MANAGER:
			manager = new GhostsManager();
			break;
		default:
			break;
	}

	return manager;
}

void RenderEngine::render()
{
	/*if(m_vao == 0)
		return; //No VAO, no render!

	//Bind program
	glUseProgram(m_programID);

	//Bind VAO
	glBindVertexArray(m_vao);

	if(m_type == TEXTURED)
		glBindTexture(GL_TEXTURE_2D, m_textureID);

	glDrawArrays(GL_TRIANGLES, 0, m_vertexCount);

	//Débindind du vao de la cible pour éviter de le remodifier
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);*/
}
