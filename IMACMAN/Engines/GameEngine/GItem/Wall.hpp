#ifndef WALL_HPP
#define WALL_HPP

#include "StaticItem.hpp"

class Wall: public StaticItem {
private:
public:
	//CONSTRUCTOR
	Wall(glm::vec2 position, uint score = 0, enum ITEM_SYNTAX type = WALL):
        StaticItem(position, score, type)
    {}
    //DESTRUCTOR
	~Wall() = default;

    //GETTERS

    //SETTERS

    //METHODS
};

#endif /* WALL_HPP */
