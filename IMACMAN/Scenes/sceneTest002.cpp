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
	//Load and compile shader
	ShaderProgram * prog = new ShaderProgram("triangle.vs.glsl", "triangle.fs.glsl");

	//Load level
	rId levelID = GameObj->ressourcesEngine->loadAsset("level01.txt", LEVEL);
	m_level = *GameObj->ressourcesEngine->getAsset(levelID);

	//Generate Sphere
	m_sphere = GameObj->ressourcesEngine->genSphere(1, 32, 32);
	m_sphere->generate(PACMAN_M);
	m_sphere->setProgram(prog);
	m_sphere->getCursor()->translate(1, 0, 0)->rotate(25, 1, 1, 1);

	//Generate Cube
	m_cube = GameObj->ressourcesEngine->genCube(1);
	m_cube->generate(GRID_M);
	m_cube->setProgram(prog);
	m_cube->getCursor()->rotate(-15, 1, 0, 0);

	std::cout << "sceneTest002 loaded" << std::endl;
}

void sceneTest002::execute()
{
	m_sphere->getCursor()->rotate(.01, 0, 1, 0);
	m_cube->getCursor()->rotate(.01, .5, 1, 0);
}

void sceneTest002::render()
{
	GameObj->renderEngine->render(m_sphere, m_sphere->getCursor());
	GameObj->renderEngine->render(m_cube, m_cube->getCursor());

	//std::cout << "rendered" << std::endl;
}
