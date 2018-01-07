#ifndef GRID_HPP
#define GRID_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <iterator>

#include "GItemFactory.hpp"

class Grid {
private:
    std::vector<GItem *> m_gridItems;
    uint m_width;
    uint m_height;
    int m_nbOfGums;

    std::map<enum ITEM_SYNTAX, char> m_displayMap = {
		{ITEM_SYNTAX::FLOOR, ' '},
		{ITEM_SYNTAX::WALL, '@'},
		{ITEM_SYNTAX::PAC_GUM, '.'},
		{ITEM_SYNTAX::SUPER_PAC_GUM, '*'},
		{ITEM_SYNTAX::FRUIT, 'F'},
		{ITEM_SYNTAX::PACMAN, 'P'},
		{ITEM_SYNTAX::BLINKY, 'B'},
		{ITEM_SYNTAX::PINKY, 'Y'},
		{ITEM_SYNTAX::INKY, 'I'},
		{ITEM_SYNTAX::CLYDE, 'C'}
	};

public:
    //CONSTRUCTOR
    Grid() = default;
    Grid(uint width, uint height, std::vector<int> level):
        m_width(width),
        m_height(height),
        m_nbOfGums(0)
    {
        int countGums = loadGrid(level);
        std::cout << "GUMS: " << countGums << std::endl;
        m_nbOfGums = countGums;
        
    }
    //DESTRUCTOR
    ~Grid() = default;

    //GETTERS
    uint getWidth() const;
    uint getHeight() const;
    std::vector<GItem *> getGrid() const;
    std::vector<GItem *> getItem(glm::vec2 position) const;
    GItem * getItem(enum ITEM_SYNTAX type) const;
    bool checkItemsExist(std::vector<enum ITEM_SYNTAX> types) const;
    inline bool isThereGums() { return m_nbOfGums; }

    //SETTERS
    int loadGrid(std::vector<int> level);
    
    //METHODS
    void moveItems();
    void moveItem(GItem * item);
    void deleteGridItem(GItem * item);
    void updateCase(Pacman * pac, std::vector<GItem *> cell);
    void pacmanFoodCollision(Pacman * pac, GItem * food);
    uint pacmanGhostCollision(Pacman * pac, Ghost * ghost);
    void displayGrid();
};

#endif /* GRID_HPP */