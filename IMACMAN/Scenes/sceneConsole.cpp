//
//  sceneTest001.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 28/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "sceneConsole.hpp"

void sceneConsole::load()
{
	Scene * scene = new sceneConsole();
	scene->init();

	GameObj->addScene(scene);
}

void sceneConsole::init()
{
	m_sceneID = 1;

	rId levelID = GameObj->ressourcesEngine->loadAsset("level01.txt", LEVEL);
	m_level = *GameObj->ressourcesEngine->getAsset(levelID);

	std::cout << "loaded" << std::endl;
}

void sceneConsole::execute()
{
	//std::cout << "executed" << std::endl;
}

void sceneConsole::render()
{
	system("clear");
	char c;
	std::cout << "PACMAN CONSOLE" << std::endl;

	for (uint i = 0; i < m_level->getHeight(); ++i) {
		for (uint j = 0; j < m_level->getWidth(); ++j) {
			c = m_map[(m_level->getLevelGrid()[i * m_level->getWidth() + j])];
			std::cout << c << " ";
		}
		std::cout << std::endl;
	}
}
