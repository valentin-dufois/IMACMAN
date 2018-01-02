#ifndef GRID_HPP
#define GRID_HPP

#include <iostream>
#include <vector>
#include "Wall.hpp"

class Grid {
    private:
    uint m_width;
    uint m_height;
    std::vector<int> m_grid;
    std::vector<Wall> m_walls;

    public:

};

#endif /* GRID_HPP */