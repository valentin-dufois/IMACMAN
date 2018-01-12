//
//  victoryScene.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 12/01/2018.
//  Copyright © 2018 Valentin Dufois. All rights reserved.
//

#include "victoryScene.hpp"

#include "Engines/RessourcesEngine/Elements/Asset.hpp"

#include <iomanip>

void victoryScene::load()
{
	Scene * scene = new victoryScene();
	scene->init();

	GameObj->addScene(scene);
}

void victoryScene::init()
{
	loadAssets();

	Item * background = new Item(ITEM_IMAGE, 0, 0, GameObj->screenWidth, GameObj->screenHeight, nullptr);
	background->setTextures(m_background, m_background);
	background->setZIndex(10);

	Item * victoryText = new Item(ITEM_TEXT, 240, 225, 0, 0, nullptr);
	victoryText->setFont(m_font, "Victory!");

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

	std::cout << "victoryScene loaded" << std::endl;
}

void victoryScene::execute()
{
	m_interface.execute();

	std::cout << "victoryScene executed" << std::endl;
}

void victoryScene::render()
{
	m_interface.render();

	std::cout << "victoryScene rendered" << std::endl;
}

void victoryScene::loadAssets()
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

victoryScene::~victoryScene() {}
