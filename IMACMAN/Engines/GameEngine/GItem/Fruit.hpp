#ifndef FRUIT_HPP
#define FRUIT_HPP

#include "StaticItem.hpp"

class Fruit: public StaticItem {
private:

public:
	//CONSTRUCTOR
	Fruit(glm::vec2 position, uint score = 100, enum ITEM_SYNTAX type = FRUIT, bool eaten = false) :
		StaticItem(position, score, type)
	{};
	//DESTRUCTOR
	~Fruit() = default;
	
	//GETTERS

	//SETTERS
};

#endif /* FRUIT_HPP */
