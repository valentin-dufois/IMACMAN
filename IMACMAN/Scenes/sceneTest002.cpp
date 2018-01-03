//
//  sceneTest001.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 28/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "sceneTest002.hpp"

void sceneTest002::load()
{
	Scene * scene = new sceneTest002();
	scene->init();

	GameObj->addScene(scene);
}

void sceneTest002::init()
{
	m_sceneID = 1;
	rId levelID = GameObj->ressourcesEngine->loadAsset("level01.txt", LEVEL);
	m_level = *GameObj->ressourcesEngine->getAsset(levelID);

	m_sphere = GameObj->ressourcesEngine->genSphere(1, 4, 4);
	std::vector<Vertex> vertices = m_sphere->getVertexList();
	
	GameObj->renderEngine->initVBO(
		GameObj->renderEngine->getBufferPtr(MANAGER_TYPE::PACMAN_M),
		MANAGER_TYPE::PACMAN_M,
		&vertices,
		36,
		1
	);

	GameObj->renderEngine->initVAO(
		MANAGER_TYPE::PACMAN_M
	);

	std::cout << "loaded" << std::endl;
}

void sceneTest002::execute()
{
	//std::cout << "executed" << std::endl;
}

void sceneTest002::render()
{
	//std::cout << "rendered" << std::endl;
}
