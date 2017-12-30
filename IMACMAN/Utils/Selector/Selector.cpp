//
//  Selector.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 24/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "Selector.hpp"

Selector::Selector():
m_currentItem(nullptr) {};

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

void Selector::execute()
{
	if(m_currentItem == nullptr)
		return;

	if(GameObj->gameEngine->getkeys().DOWN)
		return moveCursor(m_currentItem->getBottomNeighboor());

	if(GameObj->gameEngine->getkeys().UP)
		return moveCursor(m_currentItem->getTopNeighboor());

	if(GameObj->gameEngine->getkeys().RIGHT)
		return moveCursor(m_currentItem->getRightNeighboor());

	if(GameObj->gameEngine->getkeys().LEFT)
		return moveCursor(m_currentItem->getLeftNeighboor());

	if(GameObj->gameEngine->getkeys().ENTER)
		return m_currentItem->action();
}

void Selector::render()
{
	for(std::vector<Item *>::iterator it = m_items.begin(); it != m_items.end(); ++it)
        (*it)->print();
}

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

Selector::~Selector()
{
	for(std::vector<Item *>::iterator it = m_items.begin(); it != m_items.end(); ++it)
        delete (*it);
}
