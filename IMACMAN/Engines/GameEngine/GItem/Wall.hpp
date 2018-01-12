#ifndef WALL_HPP
#define WALL_HPP

#include "StaticItem.hpp"

class Wall: public StaticItem {
private:
public:
	//CONSTRUCTOR
	Wall(Mesh * mesh, glm::vec2 position, uint score = 0, ITEM_SYNTAX type = WALL):
        StaticItem(mesh, position, score, type)
    {}
    //DESTRUCTOR
	~Wall() = default;

    //GETTERS

    //SETTERS

    //METHODS
};

#endif /* WALL_HPP */
