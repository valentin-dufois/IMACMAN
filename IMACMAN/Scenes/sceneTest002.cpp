//
//  sceneTest001.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 28/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "sceneTest002.hpp"
#include "../Utils/Primitive/Sphere.hpp"

void sceneTest002::load()
{
	Scene * scene = new sceneTest002();
	scene->init();

	GameObj->addScene(scene);
}

void sceneTest002::init()
{
	m_sceneID = 1;
	GLuint sphereID = 1;
	Sphere sphere = Sphere(1, 32, 16);
	GameObject->renderEngine->initVBO(GL_ARRAY_BUFFER, sphereID, 1);

	std::cout << "loaded" << std::endl;
}

void sceneTest002::execute()
{
	std::cout << "executed" << std::endl;
}

void sceneTest002::render()
{





	std::cout << "rendered" << std::endl;
}
