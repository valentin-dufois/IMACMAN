//
//  Item.cpp
//  Music Composer
//
//  Created by Valentin Dufois on 24/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "Item.hpp"

Item::Item(const ITEM_TYPE &type, const uint &posX, const uint &posY, const uint &width, const uint &height, std::function<void()> callback):
	m_display(true),
	m_type(type),
	m_posX(posX),
	m_posY(posY),
	m_width(width),
	m_height(height),
	m_selected(false),
	m_topItem(nullptr),
	m_rightItem(nullptr),
	m_bottomItem(nullptr),
    m_leftItem(nullptr),
	m_tile(nullptr),
	m_idleTexture(0),
	m_activeTexture(0),
	m_font(nullptr),
	m_callback(callback)
{
	if(type == ITEM_IMAGE)
	{
		m_tile = GameObj->ressourcesEngine->gen2DTile(m_posX, m_posY, m_width, m_height);
		m_tile->generate();
	}
}

void Item::setNeighboors(Item *top, Item *right, Item *bottom, Item *left)
{
	m_topItem = top;
	m_rightItem = right;
	m_bottomItem = bottom;
	m_leftItem = left;
}

void Item::setTextures(const GLuint &idleTexture, const GLuint &activeTexture)
{
	m_idleTexture = idleTexture;
	m_activeTexture = activeTexture;
}

void Item::setTextures(const rId &idleTexture, const rId &activeTexture)
{
	m_idleTexture = ((Image*)(GameObj->ressourcesEngine->getAsset(idleTexture)))->getTextureID();
	m_activeTexture = ((Image*)(GameObj->ressourcesEngine->getAsset(activeTexture)))->getTextureID();;
}

void Item::setFont(Font * font, const std::string &caption)
{
	m_font = font;
	m_height = m_font->getHeight();

	setCaption(caption);
}

void Item::setCaption(const std::string &caption)
{
	if(m_caption == caption)
		return;
	
	m_caption = caption;

	m_tile = m_font->genCaption(m_caption);
	m_tile->setProgram(GameObj->getDefaultProgram());
	m_tile->getCursor()->translate(m_posX, m_posY, 0);
	m_tile->generate();
}

Item * Item::getTopNeighboor()
{
	return m_topItem;
}

Item * Item::getRightNeighboor()
{
	return m_rightItem;
}

Item * Item::getBottomNeighboor()
{
	return m_bottomItem;
}

Item * Item::getLeftNeighboor()
{
	return m_leftItem;
}

bool Item::isSelected()
{
	return m_selected;
}

void Item::select()
{
	m_selected = true;
}

void Item::deSelect()
{
	m_selected = false;
}

bool Item::isShown()
{
    return m_display;
}

void Item::hide()
{
	m_display = false;
}

void Item::show()
{
	m_display = true;
}

void Item::print()
{
	//Shall we display it or not ?
	if(!m_display)
		return;

	if(m_type == ITEM_IMAGE)
	{
		//Set item texture according to state
		if(isSelected())
			m_tile->setTexture(m_activeTexture);
		else
			m_tile->setTexture(m_idleTexture);
	}

	//Display item
	DrawCursor pos = m_tile->getCursor()->getMatrix();
	GameObj->renderEngine->render(m_tile, pos.translate(0, 0, m_zIndex));
}

void Item::action()
{
    if(m_callback == nullptr)
        return;
    
	m_callback();
}
