//
//  Level.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "Level.hpp"

//Getters
uint Level::getWidth() const
{
    return m_width;
}

uint Level::getHeight() const
{
    return m_height;
}

std::vector<int> Level::getLevelGrid() const
{
    return m_levelGrid;
}
