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

	//Set font size
	m_font->setHeight(50.f);

	//Generate
	m_fontFace = m_font->genFontFace();

	//Simple tile
	Item * test01 = new Item(10, 10, m_fontFace.chars['h'].size.x, m_fontFace.chars['h'].size.y, "", nullptr);
	test01->setTextures(m_fontFace.chars['h'].texture, m_fontFace.chars['h'].texture);

	m_menu.addItem(test01);
	m_caption = m_font->genCaption("Hello World");


	std::cout << "loaded" << std::endl;
}

void sceneTest001::execute()
{
	m_caption->getCursor()->translate(0, .01f, 0);
	std::cout << "executed" << std::endl;
}

void sceneTest001::render()
{
	//m_menu.render();
	GameObj->renderEngine->setProjection2D();
	GameObj->renderEngine->render(m_caption, m_caption->getCursor());
	
	std::cout << "rendered" << std::endl;
}
