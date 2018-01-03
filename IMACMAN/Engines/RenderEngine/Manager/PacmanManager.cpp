//
//  PackmanManager.cpp
//  IMACMAN
//
//  Created by Gaëlle Calmels on 19/12/2017.
//  Copyright © 2017 Gaëlle Calmels. All rights reserved.
//

#include <iostream>

#include "Manager.hpp"
#include "PacmanManager.hpp"

void PacmanManager::init()
{

}

void PacmanManager::render()
{
  
}

void PacmanManager::fillVBO(uint nbOfVertex, std::vector<Vertex> * vertices)
{
  GLsizeiptr size = nbOfVertex * sizeof(GLfloat);

	//Fill VBO with data
	glBufferData(
    GL_ARRAY_BUFFER,
    size,
    vertices->data(),
    GL_STATIC_DRAW
  );

   std::cout << "Fill the Pacman VBO\n" << std::endl;
}

void PacmanManager::fillVAO()
{
  std::cout << "Fill the Pacman VBO\n" << std::endl;
}

void PacmanManager::updateVBO()
{

}

void PacmanManager::updateVAO()
{

}