#ifndef STATIC_ITEM_HPP
#define STATIC_ITEM_HPP

#include "GItem.hpp"

class StaticItem: public GItem {
protected:

public:
    //CONSTRUCTOR
	StaticItem(glm::vec2 position, uint score):
        GItem(position, score)
    {}
    //DESTRUCTOR
	~StaticItem();

    //GETTERS

    //SETTERS

    //METHODS
};

#endif /* STATIC_ITEM_HPP */
