//
//  Mesh.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "Mesh.hpp"

Mesh::Mesh(const std::vector<Vertex> &vertexList): Asset(MESH), m_vertexList(vertexList), m_type(COLORED), m_textureID(0), m_programID(0), m_vbo(0), m_vao(0) {}

void Mesh::appendVertex(const std::vector<Vertex> &vertexList)
{
	m_vertexList.insert(m_vertexList.end(), vertexList.begin(), vertexList.end());
}

void Mesh::appendVertex(const Vertex &vertex)
{
	m_vertexList.push_back(vertex);
}

GLuint Mesh::genVBO()
{
	//Create and bind VB0
	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

	m_vertexCount = (uint)m_vertexList.size();

	//Fill VBO with data
	glBufferData(GL_ARRAY_BUFFER, m_vertexCount * sizeof(Vertex), m_vertexList.data(), GL_STATIC_DRAW);

	//Unbind VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	return m_vbo;
}

GLuint Mesh::genVAO()
{
	if(m_vbo == 0)
		return 0; //No VBO, no VAO!

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

	/**
	 Tell OpenGL where to find data for each vertice passed

	 @param VERTEX_ATTR_POSITION To which hook the data must be linked
	 @param 2 The number of variable in the data (vec2 -> 2)
	 @param GL_FLOAT The type of variables
	 @param GL_FALSE do not touch
	 @param Vertex2DColor The data
	 @return The offset (if needed)
	 */
	glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(VERTEX_ATTR_COLOR, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *) offsetof(Vertex, color));
	glVertexAttribPointer(VERTEX_ATTR_UV, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *) offsetof(Vertex, UV));

	//Unbind everything
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	return m_vao;
}

void Mesh::render() const
{
	if(m_vao == 0)
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
	glBindVertexArray(0);
}
