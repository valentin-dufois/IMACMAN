//
//  loadingScene.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 11/01/2018.
//  Copyright © 2018 Valentin Dufois. All rights reserved.
//

#include "loadingScene.hpp"

void loadingScene::load()
{
	Scene * scene = new loadingScene();
	scene->init();

	GameObj->addScene(scene);
}

void loadingScene::init()
{
	loadAssets();

	Item * background = new Item(ITEM_IMAGE, 0, 0, GameObj->screenWidth, GameObj->screenHeight, nullptr);
	background->setTextures(m_background, m_background);
	background->setZIndex(10);

	m_interface.addItem(background);

	//std::cout << "loadingScene loaded" << std::endl;
}

void loadingScene::execute()
{
	m_interface.execute();

	if(!m_firstPass)
	{
		GameObj->removeScene(this);
		gameScene::load();
	}

	//std::cout << "loadingScene executed" << std::endl;
}

void loadingScene::render()
{
	m_interface.render();

	m_firstPass = false;

	//std::cout << "loadingScene rendered" << std::endl;
}

void loadingScene::loadAssets()
{
	m_background = GameObj->ressourcesEngine->loadAsset("Loading_Background.jpg", IMAGE);
}

