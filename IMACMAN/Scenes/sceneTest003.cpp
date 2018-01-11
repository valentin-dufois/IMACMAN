//
//  sceneTest003.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 09/01/2018.
//  Copyright © 2018 Valentin Dufois. All rights reserved.
//

#include "sceneTest003.hpp"

void sceneTest003::load()
{
	Scene * scene = new sceneTest003();
	scene->init();

	GameObj->addScene(scene);
}

void sceneTest003::init()
{
	GameObj->renderEngine->getCameraCursor()->translate(0, 0, -10);

	//////
	//MESH
	rId meshID = GameObj->ressourcesEngine->loadAsset("pacman.blend", MESH);
	rId texID = GameObj->ressourcesEngine->loadAsset("pac.png", IMAGE);
	rId texID2 = GameObj->ressourcesEngine->loadAsset("eye.jpg", IMAGE);
	rId fontID = GameObj->ressourcesEngine->loadAsset("8-BITWONDER.TTF", FONT);

	m_mesh = *GameObj->ressourcesEngine->getAsset(meshID);
	m_font = *GameObj->ressourcesEngine->getAsset(fontID);
	m_tex = *GameObj->ressourcesEngine->getAsset(texID);
	Image * tex2 = *GameObj->ressourcesEngine->getAsset(texID2);

	m_mesh->generate();
	m_mesh->setProgram(GameObj->getDefaultProgram());
	m_mesh->setTexture(m_tex->getTextureID());

	m_font->setHeight(100.f);
	m_font->generate();

	Item * test01 = new Item(ITEM_IMAGE, 10, 10, 100, 100, nullptr);
	test01->setTextures(m_tex->getTextureID(), tex2->getTextureID());

	Item * test02 = new Item(ITEM_IMAGE, 120, 10, 100, 100, nullptr);
	test02->setTextures(m_tex->getTextureID(), tex2->getTextureID());

	Item * test03 = new Item(ITEM_TEXT, 230, 10, 100, 100, nullptr);
	test03->setFont(m_font, "IMACMAN");

	test01->setNeighboors(nullptr, test02, nullptr, nullptr);
	test02->setNeighboors(nullptr, nullptr, nullptr, test01);

	m_menu.addItem(test01);
	m_menu.addItem(test02);
	m_menu.addItem(test03);

	std::cout << "loaded" << std::endl;
}

void sceneTest003::execute()
{
	m_mesh->getCursor()->rotate(1, 1, 1, 1);
	m_menu.execute();
	std::cout << "executed" << std::endl;
}

void sceneTest003::render()
{
	GameObj->renderEngine->setProjection3D();
	GameObj->renderEngine->render(m_mesh, m_mesh->getCursor());

	m_menu.render();

	std::cout << "rendered" << std::endl;
}