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
#include "Utils/Enums.hpp"
#include "Engines/RessourcesEngine/Elements/Mesh.hpp"

#include "Manager/Manager.hpp"
#include "Core/GameObject.hpp"

#include <map>

//The engine
class RenderEngine
{
public:
	//Singleton
	static void instanciate();

	/**
	 Return the object manager for the given type

	 @param type Type of the manager
	 @return The Manager
	 */
	Manager * getManager(enum MANAGER_TYPE type);

	//getters
	GLuint * getBufferPtr(enum MANAGER_TYPE type);

	///////
	//Utils
	void loadPlateBoard();
	void updatePlateBoard();

	void loadGrid();
	void updateGrid();
	void renderGrid();

	void initVBO(Mesh * mesh, enum MANAGER_TYPE type);
	void initVAO(Mesh * mesh, enum MANAGER_TYPE type);
	void render(Mesh * mesh);

private:
	//Singleton
	static bool m_instanciated;
	//Vertice Properties
	const GLuint VERTEX_ATTR_POSITION = 1;
	const GLuint VERTEX_ATTR_NORMAL = 2;
	const GLuint VERTEX_ATTR_COLOR = 3;
	const GLuint VERTEX_ATTR_UV = 4;
	//Attributs
	GLuint * m_gridVBO;
	GLuint * m_pacmanVBO;
	std::vector<GLuint *> m_ghostsVBO;
	uint m_VBOCountIndex;
	//Cameras
	bool thirdPersCamera = false;

	//Constructor
	RenderEngine();
	~RenderEngine();
};

//////////////////
//OpenGL Debugging
#include <iostream>
void _check_gl_error(const char *file, int line);
#define check_gl_error() _check_gl_error(__FILE__,__LINE__)
//////////////////

#endif /* RenderEngine_hpp */
