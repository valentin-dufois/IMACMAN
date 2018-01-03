#ifndef FRUIT_HPP
#define FRUIT_HPP

#include "StaticItem.hpp"

class Fruit: public StaticItem {
private:
	bool m_eaten;

public:
	//CONSTRUCTOR
	Fruit(glm::vec2 position, uint score = 100, bool superGum = false, bool eaten = false) :
		StaticItem(position, score),
		m_eaten(eaten)
	{};
	//DESTRUCTOR
	~Fruit();
	
	//GETTERS
	bool getEatenState() const;

	//SETTERS
	void updateEatenState(bool eaten);
};

#endif /* FRUIT_HPP */
