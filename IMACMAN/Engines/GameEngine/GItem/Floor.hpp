#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "StaticItem.hpp"

class Floor: public StaticItem {
private:
public:
	//CONSTRUCTOR
	Floor(Mesh * mesh, glm::vec2 position, uint score = 0, enum ITEM_SYNTAX type = FLOOR):
        StaticItem(mesh, position, score, type)
    {}
    //DESTRUCTOR
	~Floor() = default;

    //GETTERS

    //SETTERS

    //METHODS
};

#endif /* FLOOR_HPP */
