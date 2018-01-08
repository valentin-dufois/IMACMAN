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
	ShaderProgram * prog = new ShaderProgram("3D.vs.glsl", "directionallight.fs.glsl");

	m_sceneID = 1; // ??????

	//Load level
	rId levelID = GameObj->ressourcesEngine->loadAsset("level01.txt", LEVEL);
	m_level = *GameObj->ressourcesEngine->getAsset(levelID);

	//Generate Sphere
	m_sphere = GameObj->ressourcesEngine->genSphere(1, 32, 32);
	m_sphere->generate(PACMAN_M);
	m_sphere->setProgram(prog);

	glm::mat4 matID(1.0f);
	glm::mat4 scaleMatrix = glm::scale(matID, glm::vec3(.5f, .5f, 0));

	prog->setUniformMat4("uMVPMatrix", scaleMatrix);

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

	//std::cout << "rendered" << std::endl;
}
