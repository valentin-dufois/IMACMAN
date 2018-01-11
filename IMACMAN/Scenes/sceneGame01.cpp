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
	float levelHalfWidth = (float) GameObj->gameEngine->getGrid()->getWidth() / 2;
	float levelHalfHeight = (float) GameObj->gameEngine->getGrid()->getHeight() / 2;

	GameObj->renderEngine->getCameraCursor()
	->rotate(-90.f, glm::vec3(0, 0, 1))
	->translate(-levelHalfWidth, -levelHalfHeight, -22);

	std::cout << "sceneGame loaded" << std::endl;

	//Load interface
	gameOverlay::load();
}

void sceneGame01::execute()
{
	GameObj->gameEngine->inGameChecks();

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

	std::cout << "sceneGame executed" << std::endl;
}

void sceneGame01::render()
{
	this->renderMeshList(m_gridLevel->getGrid());

	std::cout << "sceneGame rendered" << std::endl;
}

void sceneGame01::renderMesh(Mesh * mesh) {
	GameObj->renderEngine->render(
		mesh,
		mesh->getCursor()
	);
}

void sceneGame01::renderMeshList(std::vector<GItem *> * meshList) {
	std::vector<GItem *>::const_iterator it;

	for (it = m_gridLevel->getGrid()->begin(); it != m_gridLevel->getGrid()->end(); ++it) {
		GameObj->renderEngine->render(
			(*it)->getMesh(),
			(*it)->getMesh()->getCursor()
		);
	}
}
