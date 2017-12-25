//
//  RenderEngine.cpp
//  IMACMAN
//
//  Created by Gaëlle Calmels on 19/12/2017.
//  Copyright © 2017 Gaëlle Calmels. All rights reserved.
//

#include "../../main.hpp"
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
	initVBO(GL_ARRAY_BUFFER, &m_gridVBO, GRID_MANAGER);

	m_pacmanVBO = pacmanVBO;
	initVBO(GL_ARRAY_BUFFER, &m_pacmanVBO, GRID_MANAGER);

	m_ghostsVBO = ghostsVBO;
	initVBO(GL_ARRAY_BUFFER, &m_ghostsVBO[0] , GRID_MANAGER);
	initVBO(GL_ARRAY_BUFFER, &m_ghostsVBO[1], GRID_MANAGER);
	initVBO(GL_ARRAY_BUFFER, &m_ghostsVBO[2], GRID_MANAGER);
}

void RenderEngine::initVBO(GLenum bufferType, GLuint * index, managerType type, GLuint nbOfVBO)
{
	//Get Manager for the future VBO
	Manager * manager = getManager(type);
	//Generate VBO
	glGenBuffers(nbOfVBO, index);
	//Bind the VBO to OpenGL
	glBindBuffer(bufferType, *index);
	//Fill the VBO with data
	manager->fillVBO();
	//Unbind the VBO from OpenGL
	glBindBuffer(bufferType, 0);
}

Manager * RenderEngine::getManager(managerType type)
{
	Manager * manager = nullptr;

	switch (type)
	{
		/*case GRID_MANAGER:
			manager = new GridManager();
			break;
		case PACMAN_MANAGER:
			manager = new ShaderImporter();
			break;
		case GHOST_MANAGER:
			manager = new SoundImporter();
			break;*/
		default:
			break;
	}

	return manager;
}
