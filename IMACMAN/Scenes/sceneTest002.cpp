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

	m_cube = GameObj->ressourcesEngine->genCube(1);
	std::vector<Vertex> vertices = m_cube->getVertexList();
	
	/*GameObj->renderEngine->loadPlateBoard(
		GL_ARRAY_BUFFER,
		"testVBO",
		managerType::GRID_MANAGER,
		&vertices,
		36,
		1
	);*/

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
