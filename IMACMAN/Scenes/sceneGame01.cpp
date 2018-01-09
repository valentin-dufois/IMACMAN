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
	//Load and compile shader
	scene_prog = new ShaderProgram("triangle.vs.glsl", "triangle.fs.glsl");

	//Load level
	rId levelID = GameObj->ressourcesEngine->loadAsset("level00.txt", LEVEL);
	m_level = *GameObj->ressourcesEngine->getAsset(levelID);

	//Load the level inside the Game Engine
	GameObj->gameEngine->loadLevel(m_level);
	
	m_levelWalls = this->getItemMesh(GameObj->gameEngine->getGrid()->getItemList(ITEM_SYNTAX::WALL));
	m_levelGums = this->getItemMesh(GameObj->gameEngine->getGrid()->getItemList(ITEM_SYNTAX::PAC_GUM));
	m_levelSuperGums = this->getItemMesh(GameObj->gameEngine->getGrid()->getItemList(ITEM_SYNTAX::SUPER_PAC_GUM));

	//Generate Sphere
	/*m_sphere = GameObj->ressourcesEngine->genSphere(1, 32, 32);
	m_sphere->generate(PACMAN_M);
	m_sphere->setProgram(scene_prog);
	m_sphere->getCursor()->scale(.5f, .5f, .5f)->rotate(25, 1, 1, 1);*/

	std::cout << "sceneGame01 loaded" << std::endl;

	GameObj->renderEngine->initRender();
}

void sceneGame01::execute()
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

void sceneGame01::render()
{
	this->renderMeshList(m_levelWalls);
}

void sceneGame01::renderMeshList(std::vector<GItem *> meshList) {
	std::vector<GItem *>::const_iterator it;
	
	for (it = meshList.begin(); it < meshList.end(); ++it) {
		GameObj->renderEngine->render(
			(*it)->getMesh(),
			(*it)->getMesh()->getCursor()
		);
	}
}