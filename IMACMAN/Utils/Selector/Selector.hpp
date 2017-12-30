//
//  Selector.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 24/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef Selector_hpp
#define Selector_hpp

#include "Core/GameObject.hpp"
#include "Engines/GameEngine/GameEngine.hpp"
#include "Item.hpp"
#include <vector>

class Selector
{
public:

	Selector();

	void addItem(Item * newItem);
	void execute();
    void render();

	~Selector();

private:

	std::vector<Item *> m_items;
	Item * m_currentItem;

	void moveCursor(Item * item);
};

#endif /* Selector_hpp */
