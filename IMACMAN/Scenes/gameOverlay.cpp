//
//  gameOverlay.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 11/01/2018.
//  Copyright © 2018 Valentin Dufois. All rights reserved.
//

#include "gameOverlay.hpp"

#include "Engines/RessourcesEngine/Elements/Asset.hpp"

#include <iomanip>

void gameOverlay::load()
{
	Scene * scene = new gameOverlay();
	scene->init();

	GameObj->addScene(scene);
}

void gameOverlay::init()
{
	loadAssets();

	m_liveItem = new Item(ITEM_TEXT, 25, 10, 0, 0, nullptr);
	m_liveItem->setFont(m_font, "LIVES:0");

	m_scoreItem = new Item(ITEM_TEXT, 225, 10, 0, 0, nullptr);
	m_scoreItem->setFont(m_font, "SCORE:0");

	m_superItem = new Item(ITEM_TEXT, 475, 10, 0, 0, nullptr);
	m_superItem->setFont(m_font, "SUPERTIME:0");

	m_interface.addItem(m_liveItem);
	m_interface.addItem(m_scoreItem);
	m_interface.addItem(m_superItem);

	std::cout << "loaded" << std::endl;
}

void gameOverlay::execute()
{
	//m_caption->getCursor()->translate(0, .01f, 0);

	Pacman * pacman = GameObj->gameEngine->getPacman();

	m_liveItem->setCaption("LIVES:" + std::to_string(pacman->getLives()));
	m_scoreItem->setCaption("SCORE:" + std::to_string(pacman->getRealScore()));
	m_superItem->setCaption("SUPERTIME:" + std::to_string(pacman->getSuperCounter()));

	std::cout << "executed" << std::endl;
}

void gameOverlay::render()
{
	m_interface.render();

	std::cout << "rendered" << std::endl;
}

void gameOverlay::loadAssets()
{
	rId fontRId = GameObj->ressourcesEngine->loadAsset("Joystix.ttf", FONT);
	m_font = *GameObj->ressourcesEngine->getAsset(fontRId);
	m_font->setHeight(25.f);
	m_font->generate();
}

