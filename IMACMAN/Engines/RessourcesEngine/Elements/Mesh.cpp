//
//  Mesh.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "Mesh.hpp"

void Mesh::appendVertex(const std::vector<Vertex> &vertexList)
{
	m_vertexList.insert(m_vertexList.end(), vertexList.begin(), vertexList.end());
}

void Mesh::appendVertex(const Vertex &vertex)
{
	m_vertexList.push_back(vertex);
}

void Mesh::generate(MANAGER_TYPE type)
{
	GameObj->renderEngine->initVBO(this, type);

	GameObj->renderEngine->initVAO(this, type);
}

void Mesh::applyCursor()
{
	Vertex temp;

	for(std::vector<Vertex>::iterator it = m_vertexList.begin(); it!= m_vertexList.end(); ++it)
	{
		temp = *it;
		temp.position = glm::vec4((*it).position, 1) * m_cursor.getMatrix();
		temp.normal = glm::vec4((*it).normal, 0) * m_cursor.getMatrix();

		*it = temp;
	}

	m_cursor.setMatrix(glm::mat4());
}
