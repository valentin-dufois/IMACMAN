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

	//Fetch a level
	rId levelID = GameObj->ressourcesEngine->loadAsset("level01.txt", LEVEL);
	Level * level = *GameObj->ressourcesEngine->getAsset(levelID);
	
	//Load the level inside the Game Engine
	GameObj->gameEngine->loadLevel(level);

}

void sceneConsole::execute()
{
	Grid * grid = GameObj->gameEngine->getGrid();
	DynamicItem * pacman = reinterpret_cast<DynamicItem *>(grid->getItem(ITEM_SYNTAX::PACMAN));

	if (GameObj->gameEngine->getKeys().UP) {
		pacman->updateDirection(DIRECTION::UP);
	} else if (GameObj->gameEngine->getKeys().DOWN) {
		pacman->updateDirection(DIRECTION::DOWN);
	} else if (GameObj->gameEngine->getKeys().LEFT) {
		pacman->updateDirection(DIRECTION::LEFT);
	} else if (GameObj->gameEngine->getKeys().RIGHT) {
		pacman->updateDirection(DIRECTION::RIGHT);
	}

	grid->moveItems();
}

void sceneConsole::render()
{
	system("clear");
	std::cout << "----------[ PACMAN CONSOLE ]----------" << std::endl;
	GameObj->gameEngine->displayInfo();
	GameObj->gameEngine->displayLevel();
}
