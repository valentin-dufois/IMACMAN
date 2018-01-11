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

void Mesh::generate()
{
	GameObj->renderEngine->initVBO(this);

	GameObj->renderEngine->initVAO(this);
}

void Mesh::applyCursor()
{
	Vertex temp;

	for(std::vector<Vertex>::iterator it = m_vertexList.begin(); it!= m_vertexList.end(); ++it)
	{
		temp = *it;

		std::cout << glm::to_string(temp.position) << std::endl;

		temp.position = glm::vec4((*it).position, 1) * m_cursor.getMatrix();
		temp.normal = glm::vec4((*it).normal, 0) * m_cursor.getMatrix();

		std::cout << glm::to_string(temp.position) << std::endl;

		*it = temp;
	}

	m_cursor.setMatrix(glm::mat4(1.0f));
}
