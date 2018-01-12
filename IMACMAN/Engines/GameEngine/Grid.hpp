#ifndef GRID_HPP
#define GRID_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <iterator>
#include <random>
#include <chrono>

#include "GItemFactory.hpp"

class Grid
{
public:
    //CONSTRUCTOR
    Grid() = default;
    Grid(uint width, uint height, std::vector<int> level):
        m_width(width),
        m_height(height),
        m_nbOfGums(0)
    {
        m_nbOfGums = loadGrid(level);
    }
    //DESTRUCTOR
    ~Grid() = default;

	/////////
    //GETTERS

    /**
     Return the width of the grid

     @return The grid's width
     */
    inline uint getWidth() const { return m_width; }

    /**
     Return the height of the grid

     @return Grid's height
     */
    inline uint getHeight() const { return m_height; }

    /**
     Return all the item in the grid

     @return The items in a GItem* vector
     */
	inline std::vector<GItem *> * getGrid() { return &m_gridItems; };

    /**
     Return the item at the given position

     @param position Position on the grid
     @return The item
     */
    std::vector<GItem *> getItem(glm::vec2 position) const;

    /**
     Return the item of the given type

     @param type Item's type
     @return Pointer to the item
     */
    GItem * getItem(ITEM_SYNTAX type) const;

    /**
     Return all the item of a certain type

     @param type Item type
     @return The items in a GItem* vector
     */
    std::vector<GItem *> getItemList(ITEM_SYNTAX type) const;

    /**
     Check if the given item types exists in the grid

     @param types The types to check in a vector
	 @return True if all exists; false otherwise
     */
    bool checkItemsExist(std::vector<ITEM_SYNTAX> types) const;

    //SETTERS
    int loadGrid(std::vector<int> level);
    
    //METHODS
    void moveItems();
    void moveItem(GItem * item);
    
    void deleteGridItem(GItem * item);
    
    void updateCase(Pacman * pac, std::vector<GItem *> cell);
    void updateCase(Ghost * ghost, std::vector<GItem *> cell);
    
    void pacmanFoodCollision(Pacman * pac, GItem * food, glm::vec2 nextPosition);
    uint pacmanGhostCollision(Pacman * pac, Ghost * ghost);
    uint ghostPacmanCollision(Pacman * pac, Ghost * ghost);
    
    void displayGrid();


    void handleIA(DynamicItem * dItem);
    bool isNextReachable(DynamicItem * dItem, DIRECTION direction);

	DIRECTION randomMoveIA(DynamicItem * dItem);
    DIRECTION turnRightIA();
    DIRECTION stalkerIA();
    DIRECTION terminatorIA();
	DIRECTION afraidIA();

private:
	std::vector<GItem *> m_gridItems;
	uint m_width;
	uint m_height;
	int m_nbOfGums;

	std::map<ITEM_SYNTAX, char> m_displayMap = {
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
};

#endif /* GRID_HPP */
