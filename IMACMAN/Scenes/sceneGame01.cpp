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
	this->renderMeshList(m_levelGums);
	this->renderMeshList(m_levelSuperGums);
}

//SPECIFIC METHODS OF THIS SCENE
std::vector<Mesh *> sceneGame01::getItemMesh(std::vector<GItem *> items) {
	std::vector<GItem *>::const_iterator it;
	std::vector<Mesh *> meshList;
	
	for (it = items.begin(); it < items.end(); ++it) {
		meshList.push_back(genMeshWithAttributs(
			(*it)->getPosition(),
			(*it)->getItemType()
		));
	}

	return meshList;
}

Mesh * sceneGame01::genMeshWithAttributs(glm::vec2 position, enum ITEM_SYNTAX itemType) {
	Mesh * tmpMesh;
	glm::vec4 meshColor;
	float scale = 1.f;
	bool isSphere = true;

	switch(itemType) {
		case ITEM_SYNTAX::WALL:
			isSphere = false;
			meshColor = glm::vec4(0, 185, 161, 1);
			break;
		case ITEM_SYNTAX::PAC_GUM:
			scale = 0.1f;
			meshColor = glm::vec4(255, 255, 0, 1);
			break;
		case ITEM_SYNTAX::SUPER_PAC_GUM:
			scale = 0.2f;
			meshColor = glm::vec4(255, 255, 255, 1);
			break;
		case ITEM_SYNTAX::FRUIT:
			scale = 0.3f;
			meshColor = glm::vec4(255, 0, 0, 1);
			break;
		case ITEM_SYNTAX::PACMAN:
			scale = 0.6f;
			meshColor = glm::vec4(255, 255, 0, 1);
			break;
		case ITEM_SYNTAX::BLINKY:
			scale = 0.6f;
			meshColor = glm::vec4(252, 38, 1, 1);
			break;
		case ITEM_SYNTAX::PINKY:
			scale = 0.6f;
			meshColor = glm::vec4(249, 181, 180, 1);
			break;
		case ITEM_SYNTAX::INKY:
			scale = 0.6f;
			meshColor = glm::vec4(28, 219, 221, 1);
			break;
		case ITEM_SYNTAX::CLYDE:
			scale = 0.6f;
			meshColor = glm::vec4(250, 162, 14, 1);
			break;
		default:
			break;
	}
	
	if (isSphere) {
		tmpMesh = GameObj->ressourcesEngine->genSphere(scale, 16, 16, meshColor);
	} else {
		tmpMesh = GameObj->ressourcesEngine->genCube(scale, meshColor);
	}

	tmpMesh->generate(GRID_M);
	tmpMesh->setProgram(scene_prog);
	tmpMesh->getCursor()->translate(glm::vec3(position, 0));

	return tmpMesh;
}

void sceneGame01::renderMeshList(std::vector<Mesh *> meshList) {
	std::vector<Mesh *>::const_iterator it;
	
	for (it = meshList.begin(); it < meshList.end(); ++it) {
		GameObj->renderEngine->render(
			(*it),
			(*it)->getCursor()
		);
	}
}