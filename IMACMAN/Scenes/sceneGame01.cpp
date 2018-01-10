//
//  sceneTest001.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 28/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "sceneGame01.hpp"

void sceneGame01::load()
{
	Scene * scene = new sceneGame01();
	scene->init();

	GameObj->addScene(scene);
}

void sceneGame01::init()
{
	//Load level
	rId levelID = GameObj->ressourcesEngine->loadAsset("level01.txt", LEVEL);
	Level * level = *GameObj->ressourcesEngine->getAsset(levelID);

	//Load the level inside the Game Engine and get the Grid as reference
	GameObj->gameEngine->loadLevel(level);
	m_gridLevel = GameObj->gameEngine->getGrid();

	//Init renderer values
	float screenRatio = (float) GameObj->screenWidth / GameObj->screenHeight;
	float levelHalfWidth = (float) GameObj->gameEngine->getGrid()->getWidth() / 2;
	float levelHalfHeight = (float) GameObj->gameEngine->getGrid()->getHeight() / 2;

	GameObj->renderEngine->initRender(screenRatio, levelHalfWidth, levelHalfHeight);

	std::cout << "LOADED" << std::endl;
}

void sceneGame01::execute()
{
	//Get Pacman to handle moves and render
	DynamicItem * pacman = reinterpret_cast<DynamicItem *>(m_gridLevel->getItem(ITEM_SYNTAX::PACMAN));

	if (GameObj->gameEngine->getKeys().UP) {
		pacman->updateDirection(DIRECTION::UP);
	} else if (GameObj->gameEngine->getKeys().DOWN) {
		pacman->updateDirection(DIRECTION::DOWN);
	} else if (GameObj->gameEngine->getKeys().LEFT) {
		pacman->updateDirection(DIRECTION::LEFT);
	} else if (GameObj->gameEngine->getKeys().RIGHT) {
		pacman->updateDirection(DIRECTION::RIGHT);
	}

	m_gridLevel->moveItems();
	std::cout << "EXECUTED" << std::endl;
}

void sceneGame01::render()
{
	this->renderMeshList(m_gridLevel->getGrid());
}

void sceneGame01::renderMesh(Mesh * mesh) {
	GameObj->renderEngine->render(
		mesh,
		mesh->getCursor()
	);
}

void sceneGame01::renderMeshList(std::vector<GItem *> meshList) {
	std::vector<GItem *>::const_iterator it;
	
	for (it = m_gridLevel->getGrid().begin(); it < m_gridLevel->getGrid().end(); ++it) {
		GameObj->renderEngine->render(
			(*it)->getMesh(),
			(*it)->getMesh()->getCursor()
		);
	}
}