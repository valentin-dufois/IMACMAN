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
RenderEngine::RenderEngine()
{
	GLuint gridVBO, pacmanVBO, blinkyVBO, pinkyVBO, inkyVBO, clydeVBO;
	
	m_gridVBO = &gridVBO;
	m_pacmanVBO = &pacmanVBO;
	m_ghostsVBO = {
		&blinkyVBO,
		&pinkyVBO,
		&inkyVBO,
		&clydeVBO
	};
}

void RenderEngine::initRender()
{
	float screenRatio = (float) GameObj->screenWidth / GameObj->screenHeight;

	//Projection Matrix
	m_ProjectionMatrix.perspective(70.f, screenRatio, 0.1f, 100.f);

	//MV Matrix <- The camera in a sort
	//m_MVMatrix;

	//Normal
	m_NormalMatrix = m_MVMatrix;
	m_NormalMatrix.inverse()->transpose();
}


void RenderEngine::initVBO(Mesh * mesh, enum MANAGER_TYPE type)
{
	//Get Manager for VBO
	Manager * manager = getManager(type);
	
	//Generate & bind VBO
	glGenBuffers(1, &mesh->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->vbo);

	//Fill VBO with data
	std::vector<Vertex> vertexList = mesh->getVertexList();
	manager->fillVBO(vertexList);

	//Unbind VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void RenderEngine::initVAO(Mesh * mesh, enum MANAGER_TYPE type)
{
	if(mesh->vbo == 0)
		return; //No VBO, No VAO!

	glGenVertexArrays(1, &mesh->vao);
	glBindVertexArray(mesh->vao);

	glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
	glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
	glEnableVertexAttribArray(VERTEX_ATTR_COLOR);
	glEnableVertexAttribArray(VERTEX_ATTR_UV);

	//Bind mesh VBO
	glBindBuffer(GL_ARRAY_BUFFER, mesh->vbo);

	//Specify vertice properties positions
	glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *)offsetof(Vertex, normal));
	glVertexAttribPointer(VERTEX_ATTR_COLOR, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *)offsetof(Vertex, color));
	glVertexAttribPointer(VERTEX_ATTR_UV, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *)offsetof(Vertex, UV));

	//Unbind everything
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

GLuint * RenderEngine::getBufferPtr(enum MANAGER_TYPE type)
{
	GLuint * bufferPtr;

	switch (type) {
		case MANAGER_TYPE::GRID_M :
			bufferPtr = m_gridVBO;
			break;
		case MANAGER_TYPE::PACMAN_M :
			bufferPtr = m_pacmanVBO;
			break;
		case MANAGER_TYPE::BLINKY_M :
			bufferPtr = m_ghostsVBO[0];
			break;
		case MANAGER_TYPE::PINKY_M :
			bufferPtr = m_ghostsVBO[1];
			break;
		case MANAGER_TYPE::INKY_M :
			bufferPtr = m_ghostsVBO[2];
			break;
		case MANAGER_TYPE::CLYDE_M :
			bufferPtr = m_ghostsVBO[3];
			break;
		case MANAGER_TYPE::UI_ELEMENT_M :
			bufferPtr = m_ghostsVBO[3];
			break;
	}

	return bufferPtr;
}

Manager * RenderEngine::getManager(enum MANAGER_TYPE type)
{
	Manager * manager = nullptr;

	switch (type)
	{
		case MANAGER_TYPE::GRID_M :
			manager = new GridManager();
			break;
		case MANAGER_TYPE::PACMAN_M :
			manager = new PacmanManager();
			break;
		case MANAGER_TYPE::BLINKY_M :
		case MANAGER_TYPE::PINKY_M :
		case MANAGER_TYPE::INKY_M :
		case MANAGER_TYPE::CLYDE_M :
			manager = new GhostsManager();
			break;
		case MANAGER_TYPE::UI_ELEMENT_M :
			manager = new UIElementManager();
			break;
	}

	return manager;
}

void RenderEngine::render(Mesh * mesh, DrawCursor * cursor)
{
	if(mesh->vao == 0)
		return; //No VAO, no render!

	//Set program
	mesh->getProgram()->use();

	//Bind texture if needed
	if(mesh->isTextured())
	{
		glBindTexture(GL_TEXTURE_2D, mesh->getTextureID());
		mesh->getProgram()->setUniformUint("uTexturedMesh", 1);
		mesh->getProgram()->setUniformUint("uTexture", 0);
	}
	else
	{
		mesh->getProgram()->setUniformUint("uTexturedMesh", 0);
	}

	//Send uniforms to GPU
	mesh->getProgram()->setUniformMat4("uMVMatrix", m_MVMatrix);
	mesh->getProgram()->setUniformMat4("uNormalMatrix", m_NormalMatrix);
	mesh->getProgram()->setUniformMat4("uMVPMatrix", m_ProjectionMatrix * m_MVMatrix * cursor->getMatrix());

	//Bind VAO
	glBindVertexArray(mesh->vao);

	//Draw cube
	glDrawArrays(GL_TRIANGLES, 0, mesh->getVertexCount());
	check_gl_error();

	//Debind and clean
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}

void _check_gl_error(const char *file, int line)
{
	GLenum err (glGetError());

	while(err != GL_NO_ERROR)
	{
		std::string error;

		switch(err)
		{
			case GL_INVALID_OPERATION:      error="INVALID_OPERATION";      break;
			case GL_INVALID_ENUM:           error="INVALID_ENUM";           break;
			case GL_INVALID_VALUE:          error="INVALID_VALUE";          break;
			case GL_OUT_OF_MEMORY:          error="OUT_OF_MEMORY";          break;
			case GL_INVALID_FRAMEBUFFER_OPERATION:  error="INVALID_FRAMEBUFFER_OPERATION";  break;
		}

		std::cerr << "GL_" << error.c_str() << " - " << file << ":" << line << std::endl;
		err= glGetError();
	}
}
