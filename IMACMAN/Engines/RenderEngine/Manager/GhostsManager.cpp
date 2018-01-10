//
//  GhostsManager.cpp
//  IMACMAN
//
//  Created by Gaëlle Calmels on 19/12/2017.
//  Copyright © 2017 Gaëlle Calmels. All rights reserved.
//

#include <iostream>

#include "Manager.hpp"
#include "GhostsManager.hpp"

void GhostsManager::init(Ghost &ghost)
{

}

void GhostsManager::render()
{
  
}

void GhostsManager::fillVBO(std::vector<Vertex> &vertices)
{  
  GLsizeiptr size = vertices.size() * sizeof(GLfloat);

	//Fill VBO with data
	glBufferData(
    GL_ARRAY_BUFFER,
    size,
    vertices.data(),
    GL_STATIC_DRAW
  );
}

void GhostsManager::fillVAO()
{
  std::cout << "Fill the Ghosts VAO\n" << std::endl;
}

void GhostsManager::updateVBO()
{

}

void GhostsManager::updateVAO()
{

}
