//
//  gameOverScene.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 12/01/2018.
//  Copyright © 2018 Valentin Dufois. All rights reserved.
//

#include "gameOverScene.hpp"
#include "Engines/RessourcesEngine/Elements/Asset.hpp"

#include <iomanip>

void gameOverScene::load()
{
	Scene * scene = new gameOverScene();
	scene->init();

	GameObj->addScene(scene);
}

void gameOverScene::init()
{
	loadAssets();

	Item * background = new Item(ITEM_IMAGE, 0, 0, GameObj->screenWidth, GameObj->screenHeight, nullptr);
	background->setTextures(m_background, m_background);
	background->setZIndex(10);

	Item * victoryText = new Item(ITEM_TEXT, 225, 225, 0, 0, nullptr);
	victoryText->setFont(m_font, "Game Over");

	Item * startBtn = new Item(ITEM_IMAGE, 310, 480, 77, 76, [this](){
		GameObj->removeScene(this);
		loadingScene::load();
	});

	Item * quitBtn = new Item(ITEM_IMAGE, 410, 480, 77, 76, [this](){
		GameObj->removeScene(this);
		mainMenu::load();
	});

	startBtn->setTextures(m_startBtnIdle, m_startBtnActive);
	quitBtn->setTextures(m_quitBtnIdle, m_quitBtnActive);

	startBtn->setNeighboors(nullptr, quitBtn, nullptr, nullptr);
	quitBtn->setNeighboors(nullptr, nullptr, nullptr, startBtn);

	m_interface.addItem(startBtn);
	m_interface.addItem(quitBtn);
	m_interface.addItem(victoryText);
	m_interface.addItem(background);

	//std::cout << "gameOverScene loaded" << std::endl;
}

void gameOverScene::execute()
{
	m_interface.execute();

	//std::cout << "gameOverScene executed" << std::endl;
}

void gameOverScene::render()
{
	m_interface.render();

	//std::cout << "gameOverScene rendered" << std::endl;
}

void gameOverScene::loadAssets()
{
	rId fontRId = GameObj->ressourcesEngine->loadAsset("Joystix.ttf", FONT);
	m_font = *GameObj->ressourcesEngine->getAsset(fontRId);
	m_font->setHeight(50.f);
	m_font->generate();

	m_startBtnIdle = GameObj->ressourcesEngine->loadAsset("Buttons/Play_Idle.png", IMAGE);
	m_startBtnActive = GameObj->ressourcesEngine->loadAsset("Buttons/Play_Select.png", IMAGE);

	m_quitBtnIdle = GameObj->ressourcesEngine->loadAsset("Buttons/Quit_Idle.png", IMAGE);
	m_quitBtnActive = GameObj->ressourcesEngine->loadAsset("Buttons/Quit_Select.png", IMAGE);

	m_background = GameObj->ressourcesEngine->loadAsset("Menu_Background.jpg", IMAGE);
}

gameOverScene::~gameOverScene() {}
