//
//  sceneTest001.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 28/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "gameScene.hpp"

void gameScene::load()
{
	Scene * scene = new gameScene();
	scene->init();

	GameObj->addScene(scene);
}

void gameScene::init()
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
	->setMatrix(glm::mat4(1.0f))
	->rotate(-90.f, glm::vec3(0, 0, 1))
	->rotate(-9.f, glm::vec3(0, 1, 0))
	->translate(-(levelHalfWidth+4), -levelHalfHeight, -22);

	std::cout << "sceneGame loaded" << std::endl;

	//Load interface
	gameOverlay::load();
}

void gameScene::execute()
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

void gameScene::render()
{
	renderMeshList(m_gridLevel->getGrid());

	std::cout << "sceneGame rendered" << std::endl;
}

void gameScene::renderMesh(Mesh * mesh)
{
	GameObj->renderEngine->render(
		mesh,
		mesh->getCursor()
	);
}

void gameScene::renderMeshList(std::vector<GItem *> * meshList)
{
	std::vector<GItem *>::const_iterator it;

	for (it = m_gridLevel->getGrid()->begin(); it != m_gridLevel->getGrid()->end(); ++it)
	{
		DrawCursor curs = (*it)->getMesh()->getCursor()->getMatrix();

		if((*it)->getItemType() == PACMAN)
		{
			DynamicItem * dItem = reinterpret_cast<DynamicItem *>(*it);
			DIRECTION dir = dItem->getDirection();
			
			switch (dir)
			{
				case DIRECTION::UP: curs.rotate(180, 0, 0, 1); break;
				case DIRECTION::DOWN: break;
				case DIRECTION::LEFT: curs.rotate(-90, 0, 0, 1); break;
				case DIRECTION::RIGHT: curs.rotate(90, 0, 0, 1); break;
			}
		}

		GameObj->renderEngine->render(
			(*it)->getMesh(),
			&curs
		);
	}
}

gameScene::~gameScene() {}
