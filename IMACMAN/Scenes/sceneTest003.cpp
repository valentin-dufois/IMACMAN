//
//  sceneTest003.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 09/01/2018.
//  Copyright © 2018 Valentin Dufois. All rights reserved.
//

#include "sceneTest003.hpp"

void sceneTest003::load()
{
	Scene * scene = new sceneTest003();
	scene->init();

	GameObj->addScene(scene);
}

void sceneTest003::init()
{
	ShaderProgram * prog = new ShaderProgram("triangle.vs.glsl", "triangle.fs.glsl");

	//////
	//MESH
	rId meshID = GameObj->ressourcesEngine->loadAsset("pacman.blend", MESH);
	m_mesh = *GameObj->ressourcesEngine->getAsset(meshID);

	m_mesh->generate(PACMAN_M);
	m_mesh->setProgram(prog);

	std::cout << "loaded" << std::endl;
}

void sceneTest003::execute()
{
	m_mesh->getCursor()->rotate(.01, 1, 1, 1);
	std::cout << "executed" << std::endl;
}

void sceneTest003::render()
{
	GameObj->renderEngine->render(m_mesh, m_mesh->getCursor());

	std::cout << "rendered" << std::endl;
}
