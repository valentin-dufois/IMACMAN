//
//  sceneTest001.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 28/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "sceneTest001.hpp"

void sceneTest001::load()
{
	Scene * scene = new sceneTest001();
	scene->init();

	GameObj->addScene(scene);
}

void sceneTest001::init()
{
	//////
	//FONT

	//Load and get the font
	rId fontID = GameObj->ressourcesEngine->loadAsset("8-BITWONDER.TTF", FONT);
	m_font = *GameObj->ressourcesEngine->getAsset(fontID);

	//Set font size and generate
	m_font->setHeight(50.f);
	m_font->genFontFace();

	//Simple tile
	Item * test01 = new Item(ITEM_TEXT, 10, 10, 0, 0, nullptr);
	test01->setFont(m_font, "Hello world");

	m_menu.addItem(test01);

	//sceneTest003::load();

	std::cout << "loaded" << std::endl;
}

void sceneTest001::execute()
{
	//m_caption->getCursor()->translate(0, .01f, 0);
	std::cout << "executed" << std::endl;
}

void sceneTest001::render()
{
	m_menu.render();
	
	std::cout << "rendered" << std::endl;
}
