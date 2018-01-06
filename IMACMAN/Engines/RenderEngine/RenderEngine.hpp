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
private:
	//Singleton
	static bool m_instanciated;
	//Vertice Properties
	const GLuint VERTEX_ATTR_POSITION = 1;
	const GLuint VERTEX_ATTR_NORMAL = 2;
	const GLuint VERTEX_ATTR_COLOR = 3;
	//Attributs
	GLuint * m_gridVBO;
	GLuint * m_pacmanVBO;
	GLuint * m_VAO;
	std::vector<GLuint *> m_ghostsVBO;
	uint m_VBOCountIndex;
	//Cameras
	bool thirdPersCamera = false;

	//Constructor
	RenderEngine();
	~RenderEngine();

public:
	//Singleton
	static void instanciate();

	Manager * getManager(enum MANAGER_TYPE type);

	//getters
	GLuint * getBufferPtr(enum MANAGER_TYPE type);

	//Utils
	void loadPlateBoard();
	void updatePlateBoard();

	void loadGrid();
	void updateGrid();
	void renderGrid();

	void initVBO(GLuint * index, enum MANAGER_TYPE type, std::vector<Vertex> * vertices, uint nbOfVertex, GLuint nbOfVBO);
	void initVAO(enum MANAGER_TYPE type);
	void render(Mesh * mesh);
};

#endif /* RenderEngine_hpp */
