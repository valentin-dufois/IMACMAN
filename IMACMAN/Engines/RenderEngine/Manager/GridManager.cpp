//
//  GridManager.cpp
//  IMACMAN
//
//  Created by Gaëlle Calmels on 19/12/2017.
//  Copyright © 2017 Gaëlle Calmels. All rights reserved.
//

#include <iostream>

#include "Manager.hpp"
#include "GridManager.hpp"

void GridManager::init()
{

}

void GridManager::render()
{
  
}

void GridManager::fillVBO(std::vector<Vertex> &vertices)
{
  std::cout << "Fill the grid VBO\n" << std::endl;
  
  GLsizeiptr size = vertices.size() * sizeof(GLfloat);

	//Fill VBO with data
	glBufferData(
    GL_ARRAY_BUFFER,
    size,
    vertices.data(),
    GL_STATIC_DRAW
  );
}

void GridManager::fillVAO()
{
  std::cout << "Fill the grid VAO\n" << std::endl;
}

void GridManager::updateVBO()
{

}

void GridManager::updateVAO()
{

}
