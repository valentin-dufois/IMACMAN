//
//  RenderEngine.hpp
//  IMACMAN
//
//  Created by Gaëlle Calmels on 19/12/2017.
//  Copyright © 2017 Gaëlle Calmels. All rights reserved.
//

#ifndef RenderEngine_hpp
#define RenderEngine_hpp

//Get engine dependancies
#include "libraries.hpp"
#include "Utils/Vertex.hpp"

#include "Manager/Manager.hpp"
#include "Core/GameObject.hpp"

#include <map>

//Managers types
enum managerType
{
	GRID_MANAGER,
	PACMAN_MANAGER,
	GHOST_MANAGER
};

//The engine
class RenderEngine
{
private:
	//Singleton
	static bool m_instanciated;

	//Attributs
	GLuint m_gridVBO;
	GLuint m_pacmanVBO;
	std::vector<GLuint> m_ghostsVBO;

	uint m_VBOCountIndex;
	GLuint m_VAO;

	//OpenGL Error
	GLenum error;

	//Constructor
	RenderEngine(GLuint gridVBO = 1, GLuint pacmanVBO = 2, std::vector<GLuint> ghostsVBO = {3, 4, 5, 6});
	~RenderEngine();

public:
	// Renderer configuration accessible by all
	bool thirdPersCamera = false;

	//Singleton
	static void instanciate();

	//Factory
	Manager * getManager(managerType type);

	//Utils
	void loadPlateBoard();
	void updatePlateBoard();

	void loadGrid();
	void updateGrid();
	void renderGrid();

	void initVBO(GLenum bufferType, GLuint * index, managerType type, std::vector<Vertex> * vertices, uint nbOfVertex, GLuint nbOfVBO);
	void initVAO();
	void render();
};

#endif /* RenderEngine_hpp */
