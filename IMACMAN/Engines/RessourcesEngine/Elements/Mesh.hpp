//
//  Mesh.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef Mesh_hpp
#define Mesh_hpp

//Forward declaration
class ShaderProgram;

#include "Asset.hpp"
#include "Utils/ShaderProgram.hpp"
#include "Utils/DrawCursor.hpp"
#include "Utils/Vertex.hpp"
#include "Engines/RenderEngine/RenderEngine.hpp"

#include <glm/glm.hpp>

class Mesh : public Asset
{
public:
	//Constructor
	Mesh(const std::vector<Vertex> vertexList):
		Asset(MESH),
		m_vertexList(vertexList),
		m_vertexCount((uint)vertexList.size()),
		m_textureID(0)
	{};

	Mesh():
		Asset(MESH),
		m_vertexList(),
		m_vertexCount(0),
		m_textureID(0) {};

	//Getters
	/**
	 Return all vertex in the mesh
	 @return An array of vertex
	 */
	inline std::vector<Vertex> getVertexList() const { return m_vertexList; };

	/**
	 Return the number of vertex in the mesh

	 @return Number of vertex
	 */
	GLsizei getVertexCount() { return m_vertexCount; }

	/**
	 Return the texture ID used by the mesh

	 @return Texture ID
	 */
	GLuint getTextureID() const { return m_textureID; }

	/**
	 Return the program ID (Shaders) used by the mesh

	 @return Program ID
	 */
	ShaderProgram * getProgram() const { return m_program; }

	/**
	 Tell if the mesh is textured

	 @return True if textured, false otherwise
	 */
	inline bool isTextured() { return m_textureID != 0; };
	 

	//Utils
	/**
	 Fill the mesh vertex with the given ones
	 Replace existing vertex

	 @param vertexList A vector of Vertex
	 */
	inline void fillVertex(const std::vector<Vertex> &vertexList) { m_vertexList = vertexList; };
	
	/**
	 Append new vertex to the existing ones

	 @param vertexList A vector of vertex
	 */
	void appendVertex(const std::vector<Vertex> &vertexList);

	/**
	 Append a new vertex to the existing one

	 @param vertex A vertex
	 */
	void appendVertex(const Vertex &vertex);

	/**
	 Set the texture ID for the mesh

	 @param textureID The texture ID
	 */
	inline void setTexture(GLuint textureID) { m_textureID = textureID; };

	/**
	 Set the Program ID for the mesh

	 @param program The program ID
	 */
	inline void setProgram(ShaderProgram * program) { m_program = program; };

	/**
	 Generate OpenGL buffers for the mesh
	 */
	void generate();

	GLuint vbo = 0;
	GLuint vao = 0;

	/**
	 Return the drawing cursor of the object

	 @return The cursor
	 */
	inline DrawCursor * getCursor() { return &m_cursor; };

	/**
	 Apply the cursor matrix to the mesh vertex
	 then reset cursor
	 */
	void applyCursor();

	~Mesh();

private:
	//Vertex
	std::vector<Vertex> m_vertexList;
	uint m_vertexCount;

	//Position
	DrawCursor m_cursor;

	//Texture
	GLuint m_textureID;
	
	//Shader program
	ShaderProgram * m_program;
};

#endif /* Mesh_hpp */
