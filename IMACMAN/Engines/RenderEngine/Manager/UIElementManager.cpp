//
//  UIElementManager.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 06/01/2018.
//  Copyright © 2018 Valentin Dufois. All rights reserved.
//

#include <iostream>

#include "Manager.hpp"
#include "UIElementManager.hpp"

void UIElementManager::init()
{

}

void UIElementManager::render()
{

}

void UIElementManager::fillVBO(std::vector<Vertex> &vertices)
{
	GLsizeiptr size = vertices.size() * sizeof(Vertex);

	//Fill VBO with data
	glBufferData(
				 GL_ARRAY_BUFFER,
				 size,
				 vertices.data(),
				 GL_STATIC_DRAW
				 );

	std::cout << "Fill the Pacman VBO\n" << std::endl;
}

void UIElementManager::fillVAO()
{
	std::cout << "Fill the Pacman VBO\n" << std::endl;
}

void UIElementManager::updateVBO()
{

}

void UIElementManager::updateVAO()
{

}
