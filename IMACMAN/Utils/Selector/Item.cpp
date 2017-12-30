//
//  Item.cpp
//  Music Composer
//
//  Created by Valentin Dufois on 24/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "Item.hpp"

Item::Item(uint posX, uint posY, uint width, uint height, std::string caption, std::function<void()> callback):
	m_smallItem(false),
	m_display(true),
	m_posX(posX),
	m_posY(posY),
	m_width(width),
	m_height(height),
	m_caption(caption),
	m_selected(false),
	m_topItem(nullptr),
	m_rightItem(nullptr),
	m_bottomItem(nullptr),
    m_leftItem(nullptr),
	m_callback(callback) {}

void Item::setNeighboors(Item *top, Item *right, Item *bottom, Item *left)
{
	m_topItem = top;
	m_rightItem = right;
	m_bottomItem = bottom;
	m_leftItem = left;
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

void Item::setSmall()
{
	m_smallItem = true;
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

	//Display item
	//TODO
}

void Item::action()
{
    if(m_callback == nullptr)
        return;
    
	m_callback();
}
