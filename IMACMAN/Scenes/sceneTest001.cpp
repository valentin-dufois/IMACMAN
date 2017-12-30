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
	//Load and get the font
	rId fontID = GameObj->ressourcesEngine->loadAsset("Neoneon.otf", FONT);
	Font * font = *GameObj->ressourcesEngine->getAsset(fontID);

	//Set font size
	font->setHeight(24.f);

	//Generate
	m_fontFace = font->genFontFace();

	m_program = new ShaderProgram("triangle.vs.glsl", "triangle.fs.glsl");

	std::cout << "loaded" << std::endl;
}

void sceneTest001::execute()
{
	std::cout << "executed" << std::endl;
}

void sceneTest001::render()
{
	m_program->use();




	std::cout << "rendered" << std::endl;
}
