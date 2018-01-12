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

	Item * mainLogo = new Item(ITEM_IMAGE, 192, 274, 89, 97, nullptr);
	mainLogo->setTextures(m_mainLogo, m_mainLogo);

	Item * startBtn = new Item(ITEM_IMAGE, 320, 280, 77, 76, [this](){
		GameObj->removeScene(this);
		loadingScene::load();
	});

	m_helpBtn = new Item(ITEM_IMAGE, 420, 280, 77, 76, [this](){
		if(this->m_controls->isShown())
		{
			this->m_controls->hide();
			this->m_helpBtn->setTextures(m_helpBtnIdle, m_helpBtnActive);
		}
		else
		{
			this->m_controls->show();
			this->m_helpBtn->setTextures(m_helpBtnIdle, m_helpBtnTiltActive);
		}
	});

	Item * quitBtn = new Item(ITEM_IMAGE, 520, 280, 77, 76, [](){
		GameObj->endGame();
	});


	m_controls = new Item(ITEM_IMAGE, 368, 365, 196, 87, nullptr);
	m_controls->setTextures(m_controlsID, m_controlsID);
	m_controls->hide();

	startBtn->setTextures(m_startBtnIdle, m_startBtnActive);
	m_helpBtn->setTextures(m_helpBtnIdle, m_helpBtnActive);
	quitBtn->setTextures(m_quitBtnIdle, m_quitBtnActive);

	startBtn->setNeighboors(nullptr, m_helpBtn, nullptr, nullptr);
	m_helpBtn->setNeighboors(nullptr, quitBtn, nullptr, startBtn);
	quitBtn->setNeighboors(nullptr, nullptr, nullptr, m_helpBtn);

	m_menu.addItem(mainLogo);
	m_menu.addItem(startBtn);
	m_menu.addItem(m_helpBtn);
	m_menu.addItem(quitBtn);
	m_menu.addItem(m_controls);
	m_menu.addItem(background);

	m_menu.moveCursor(startBtn);

	//std::cout << "mainMenu loaded" << std::endl;
}

void mainMenu::execute()
{
	m_menu.execute();
	//std::cout << "mainMenu executed" << std::endl;
}

void mainMenu::render()
{
	m_menu.render();

	//std::cout << "mainMenu rendered" << std::endl;
}

void mainMenu::loadAssets()
{
	m_background = GameObj->ressourcesEngine->loadAsset("Menu_Background.jpg", IMAGE);
	m_mainLogo = GameObj->ressourcesEngine->loadAsset("Menu_Pacman.png", IMAGE);
	m_controlsID = GameObj->ressourcesEngine->loadAsset("Controls.png", IMAGE);

	m_startBtnIdle = GameObj->ressourcesEngine->loadAsset("Buttons/Play_Idle.png", IMAGE);
	m_startBtnActive = GameObj->ressourcesEngine->loadAsset("Buttons/Play_Select.png", IMAGE);

	m_helpBtnIdle = GameObj->ressourcesEngine->loadAsset("Buttons/Control_Idle.png", IMAGE);
	m_helpBtnActive = GameObj->ressourcesEngine->loadAsset("Buttons/Control_Select.png", IMAGE);
	m_helpBtnTiltActive = GameObj->ressourcesEngine->loadAsset("Buttons/Control_Push.png", IMAGE);

	m_quitBtnIdle = GameObj->ressourcesEngine->loadAsset("Buttons/Quit_Idle.png", IMAGE);
	m_quitBtnActive = GameObj->ressourcesEngine->loadAsset("Buttons/Quit_Select.png", IMAGE);
}
