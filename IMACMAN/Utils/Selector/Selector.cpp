//
//  Selector.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 24/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "Selector.hpp"

Selector::Selector():
	m_currentItem(nullptr)
{}


/**
 Add an item

 @param newItem newItem Item to add
 */
void Selector::addItem(Item * newItem)
{
	m_items.push_back(newItem);

	if(m_items.size() == 1)
	{
		newItem->select();
		m_currentItem = newItem;
	}
	else
	{
		newItem->deSelect();
	}
}

/**
 Execut an action for the Item
 */
void Selector::execute()
{
	if(m_currentItem == nullptr)
		return;

	if(GameObj->gameEngine->getKeys().DOWN)
		return moveCursor(m_currentItem->getBottomNeighboor());

	if(GameObj->gameEngine->getKeys().UP)
		return moveCursor(m_currentItem->getTopNeighboor());

	if(GameObj->gameEngine->getKeys().RIGHT)
		return moveCursor(m_currentItem->getRightNeighboor());

	if(GameObj->gameEngine->getKeys().LEFT)
		return moveCursor(m_currentItem->getLeftNeighboor());

	if(GameObj->gameEngine->getKeys().ENTER)
		return m_currentItem->action();
}

/**
 Render the item
 */
void Selector::render()
{
	for(std::vector<Item *>::iterator it = m_items.begin(); it != m_items.end(); ++it)
        (*it)->print();
}

/**
 Move the cursor
 
 @param item item to select
 */
void Selector::moveCursor(Item * item)
{
	if(item == nullptr)
		return;
    
    if(!item->isShown())
        return;
        
	m_currentItem->deSelect();
	item->select();

	m_currentItem = item;
}

/**
 Desctructor
*/
Selector::~Selector()
{
	for(std::vector<Item *>::iterator it = m_items.begin(); it != m_items.end(); ++it)
        delete (*it);
}
