//
//  Mesh.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#include "Asset.hpp"
#include "Utils/ShaderProgram.hpp"
#include "Utils/Vertex.hpp"
#include <glm/glm.hpp>

class Mesh : public Asset
{
private:
	//Vertex
	std::vector<Vertex> m_vertexList;
	uint m_vertexCount;
	
	uint m_positionOffset;
	uint m_normalOffset;
	uint m_textureOffset;

	//Style
	bool m_textured;
	GLuint m_textureID;
	GLuint m_programID;

public:
	//Constructor
	Mesh(const std::vector<Vertex> &vertexList):
		Asset(MESH),
		m_vertexList(vertexList),
		m_vertexCount(vertexList.size()),
		m_positionOffset(3),
		m_normalOffset(3),
		m_textureOffset(2),
		m_textured(false),
		m_textureID(0),
		m_programID(0)
	{}

	//Getters
	std::vector<Vertex> getVertexList() { return m_vertexList; }
	GLsizeiptr getVertexCount() { return m_vertexCount; }
	 

	//Utils
	inline void fillVertex(const std::vector<Vertex> &vertexList) { m_vertexList = vertexList; };
	
	void appendVertex(const std::vector<Vertex> &vertexList);
	void appendVertex(const Vertex &vertex);

	inline void setType(const bool &type) { m_textured = type; };

	inline void setTexture(GLuint textureID) { m_textureID = textureID; };
	inline void setProgram(GLuint programID) { m_programID = programID; };

	/**
	 Return all vertex in the mesh

	 @return An array of vertex
	 */
	inline std::vector<Vertex> getVertexList() const { return m_vertexList; };
};

#endif /* Mesh_hpp */
