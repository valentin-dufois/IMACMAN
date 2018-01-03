#ifndef GRID_HPP
#define GRID_HPP

#include <iostream>
#include <vector>
#include <map>

#include "GItemFactory.hpp"

class Grid {
private:
    std::vector<Gitem *> m_gridItems;
    uint m_width;
    uint m_height;

public:
    //CONSTRUCTOR
    Grid(uint width, uint height):
        m_width(width),
        m_height(height)
    {}
    //DESTRUCTOR
    ~Grid();

    //GETTERS
    uint getWidth() const;
    uint getHeight() const;
    GItem * getItem() const; //TODO: recupere item en fonction de position (cf messenger MARCO) find_if
    std::vector<GItem *> getGrid() const;

    //SETTERS
    
    //METHODS
};

#endif /* GRID_HPP */