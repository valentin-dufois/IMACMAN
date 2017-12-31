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
#include <glm/glm.hpp>

struct Vertex
{
	glm::vec3 position;
	glm::vec4 color;		//Used if Mesh.type = COLORED
	glm::vec2 UV;			//Used if Mesh.type = TEXTURED

	glm::vec3 normal;

	unsigned int vertexSize;
	unsigned int positionOffset;
	unsigned int normalOffset;
	unsigned int textureOffset;

	Vertex() {};
	Vertex(glm::vec3 pos): position(pos) {};
};

enum MeshType
{
	COLORED,
	TEXTURED
};

class Mesh : public Asset
{
public:

	Mesh(const std::vector<Vertex> &vertexList);

	inline void fillVertex(const std::vector<Vertex> &vertexList) { m_vertexList = vertexList; };

	void appendVertex(const std::vector<Vertex> &vertexList);
	void appendVertex(const Vertex &vertex);

	inline void setType(const MeshType &type) { m_type = type; };

	inline void setTexture(GLuint textureID) { m_textureID = textureID; };
	inline void setProgram(GLuint programID) { m_programID = programID; };

	GLuint genVBO();
	GLuint genVAO();

	void render() const;

	/**
	 Return all vertex in the mesh

	 @return An array of vertex
	 */
	inline std::vector<Vertex> getVertexList() const { return m_vertexList; };

private:

	//Vertex
	std::vector<Vertex> m_vertexList;
	uint m_vertexCount;

	//Style
	MeshType m_type;
	GLuint m_textureID;
	GLuint m_programID;

	//OpenGL
	GLuint m_vbo;
	GLuint m_vao;
};

#endif /* Mesh_hpp */
