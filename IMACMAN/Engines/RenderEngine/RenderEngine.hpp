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
#include "Utils/DrawCursor.hpp"
#include "Engines/RessourcesEngine/Elements/Mesh.hpp"

#include "Core/GameObject.hpp"

#include <map>
#include <glm/gtx/string_cast.hpp>
#include <glm/ext.hpp>

//The engine
class RenderEngine
{
public:
	//Singleton
	static void instanciate();


	/**
	 Init render properties such as matrix
	 */
	void initRender();

	/**
	 Set up the projection Matrix for 3D render
	 */
	void setProjection3D();

	/**
	 Fast forward call to setProjection2D with window dimensions
	 */
	void setProjection2D();
	
	/**
	 Set up the projection matrix for 2D render

	 @param width Width in px of the screen
	 @param height Height in px of the screen
	 */
	void setProjection2D(const float &width, const float &height);

	/**
	 Return the cursor of the camera.
	 Allow for camera manipulation

	 @return The camera cursor
	 */
	inline DrawCursor * getCameraCursor() { return &m_MVMatrix; };

	///////
	//Utils

	/**
	 Generate the VBO for the given mesh

	 @param mesh Mesh to generate
	 */
	void initVBO(Mesh * mesh);

	/**
	 Generate the VAO for the given mesh

	 @param mesh Mesh to generate
	 */
	void initVAO(Mesh * mesh);

	/**
	 Render the given mesh at the given location

	 @param mesh The mesh to render
	 @param cursor Cursor to the mesh position
	 */
	void render(Mesh * mesh, DrawCursor * cursor);

private:

	//Singleton
	static bool m_instanciated;

	//Vertice Properties
	const GLuint VERTEX_ATTR_POSITION = 1;
	const GLuint VERTEX_ATTR_NORMAL = 2;
	const GLuint VERTEX_ATTR_COLOR = 3;
	const GLuint VERTEX_ATTR_UV = 4;

	//Cameras
	bool thirdPersCamera = false;

	//Matrix
	DrawCursor m_ProjectionMatrix;
	DrawCursor m_MVMatrix;
	DrawCursor m_NormalMatrix;

	DrawCursor m_storedMVMatrix;
	bool m_stored;

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
