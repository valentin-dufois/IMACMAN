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

	m_sphere = GameObj->ressourcesEngine->genSphere(1, 32, 16);
	std::vector<Vertex> vertices = m_sphere->getVertexList();

	m_sphere->generate(PACMAN_M);

	ShaderProgram prog("triangle.vs.glsl", "triangle.fs.glsl");
	prog.use();

	std::cout << "loaded" << std::endl;
}

void sceneTest002::execute()
{
	//std::cout << "executed" << std::endl;
}

void sceneTest002::render()
{
	GameObj->renderEngine->render(m_sphere);
	check_gl_error();

	std::cout << "rendered" << std::endl;
}
