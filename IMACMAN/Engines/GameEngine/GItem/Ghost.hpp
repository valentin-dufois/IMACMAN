#ifndef GHOST_HPP
#define GHOST_HPP

#include "DynamicItem.hpp"

class Ghost: public DynamicItem {
private:
	bool m_isAlive;
	bool m_isAfraid;
	int m_afraidCounter;

public:

	Ghost(glm::vec2 position, std::string name, enum ITEM_SYNTAX type, uint score = 100, bool isAlive = true, bool isAfraid = false) :
		DynamicItem(position, name, score, type),
		m_isAlive(isAlive),
		m_isAfraid(isAfraid),
		m_afraidCounter(0)
	{}
	~Ghost() = default;

	//GETTERS
	bool isAlive() const;
	bool isAfraid() const;
	
	//SETTERS
	void setIsAlive(bool isAlive);
	void setIsAfraid(bool isAfraid);
	void setAfraidCounter(int time);

	//METHODS
	inline void updateAfraidCounter() {
		m_afraidCounter > 0 ? --m_afraidCounter : m_isAfraid = false;
	}
};

#endif /* GHOST_HPP */
