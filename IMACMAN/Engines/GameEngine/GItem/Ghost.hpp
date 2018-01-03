#ifndef GHOST_HPP
#define GHOST_HPP

#include "DynamicItem.hpp"

class Ghost: public DynamicItem {
private:
	bool m_isAlive;
	bool m_isAfraid;

public:

	Ghost(std::string name, glm::vec2 position, uint score = 100, bool isAlive = true, bool isAfraid = false) :
		DynamicItem(position, name, score),
		m_isAlive(isAlive),
		m_isAfraid(isAfraid)
	{}
	~Ghost();
	
	//SETTERS
	void setIsAlive(bool isAlive);
	void setIsAfraid(bool isAfraid);
	
	//GETTERS
	bool getIsAlive() const;
	bool getIsAfraid() const;

	//METHODS
};

#endif /* GHOST_HPP */
