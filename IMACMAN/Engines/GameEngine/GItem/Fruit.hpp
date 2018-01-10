#ifndef FRUIT_HPP
#define FRUIT_HPP

#include "StaticItem.hpp"

class Fruit: public StaticItem {
private:
	bool m_eaten;
	int m_popCounter;

public:
	//CONSTRUCTOR
	Fruit(Mesh * mesh, glm::vec2 position, uint score = 500, enum ITEM_SYNTAX type = FRUIT) :
		StaticItem(mesh, position, score, type),
		m_eaten(true),
		m_popCounter(50)
	{};
	//DESTRUCTOR
	~Fruit() = default;
	
	//GETTERS
	bool getEatenState() { return m_eaten; }

	//SETTERS
	inline void updateIsEaten() {
		this->m_eaten = m_popCounter > 0;
	}
	void updatePopCounter(const int time);
};

#endif /* FRUIT_HPP */
