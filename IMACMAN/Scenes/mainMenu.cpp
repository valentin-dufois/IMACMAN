//
//  mainMenu.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 11/01/2018.
//  Copyright © 2018 Valentin Dufois. All rights reserved.
//

#include "mainMenu.hpp"

void mainMenu::load()
{
	Scene * scene = new mainMenu();
	scene->init();

	GameObj->addScene(scene);
}

void mainMenu::init()
{
	loadAssets();

	Item * background = new Item(ITEM_IMAGE, 0, 0, GameObj->screenWidth, GameObj->screenHeight, nullptr);
	background->setTextures(m_background, m_background);
	background->setZIndex(10);

	Item * mainLogo = new Item(ITEM_IMAGE, 192, 274, 89, 97, nullptr);
	mainLogo->setTextures(m_mainLogo, m_mainLogo);
	mainLogo->setZIndex(5);

	Item * startBtn = new Item(ITEM_IMAGE, 320, 280, 77, 76, [this](){
		GameObj->removeScene(this);
		loadingScene::load();
	});

	Item * helpBtn = new Item(ITEM_IMAGE, 420, 280, 77, 76, nullptr);

	Item * quitBtn = new Item(ITEM_IMAGE, 520, 280, 77, 76, [](){
		GameObj->endGame();
	});

	startBtn->setTextures(m_startBtnIdle, m_startBtnActive);
	helpBtn->setTextures(m_helpBtnIdle, m_helpBtnActive);
	quitBtn->setTextures(m_quitBtnIdle, m_quitBtnActive);

	startBtn->setNeighboors(nullptr, helpBtn, nullptr, nullptr);
	helpBtn->setNeighboors(nullptr, quitBtn, nullptr, startBtn);
	quitBtn->setNeighboors(nullptr, nullptr, nullptr, helpBtn);

	m_menu.addItem(mainLogo);
	m_menu.addItem(startBtn);
	m_menu.addItem(helpBtn);
	m_menu.addItem(quitBtn);
	m_menu.addItem(background);

	m_menu.moveCursor(startBtn);

	std::cout << "mainMenu loaded" << std::endl;
}

void mainMenu::execute()
{
	m_menu.execute();
	std::cout << "mainMenu executed" << std::endl;
}

void mainMenu::render()
{
	m_menu.render();

	std::cout << "mainMenu rendered" << std::endl;
}

void mainMenu::loadAssets()
{
	m_background = GameObj->ressourcesEngine->loadAsset("Menu_Background.jpg", IMAGE);
	m_mainLogo = GameObj->ressourcesEngine->loadAsset("Menu_Pacman.png", IMAGE);

	m_startBtnIdle = GameObj->ressourcesEngine->loadAsset("Buttons/Play_Idle.png", IMAGE);
	m_startBtnActive = GameObj->ressourcesEngine->loadAsset("Buttons/Play_Select.png", IMAGE);

	m_helpBtnIdle = GameObj->ressourcesEngine->loadAsset("Buttons/Control_Idle.png", IMAGE);
	m_helpBtnActive = GameObj->ressourcesEngine->loadAsset("Buttons/Control_Select.png", IMAGE);

	m_quitBtnIdle = GameObj->ressourcesEngine->loadAsset("Buttons/Quit_Idle.png", IMAGE);
	m_quitBtnActive = GameObj->ressourcesEngine->loadAsset("Buttons/Quit_Select.png", IMAGE);
}
