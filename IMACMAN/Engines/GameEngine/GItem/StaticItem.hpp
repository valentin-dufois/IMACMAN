#ifndef STATIC_ITEM_HPP
#define STATIC_ITEM_HPP

#include "GItem.hpp"

class StaticItem: public GItem {
protected:

public:
    //CONSTRUCTOR
	StaticItem(Mesh * mesh, glm::vec2 position, uint score, ITEM_SYNTAX type):
        GItem(mesh, position, score, type)
    {}
    //DESTRUCTOR
	~StaticItem() = default;

    //GETTERS

    //SETTERS

    //METHODS  
};

#endif /* STATIC_ITEM_HPP */
