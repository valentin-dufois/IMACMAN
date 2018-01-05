#ifndef PACMAN_HPP
#define PACMAN_HPP

#include "DynamicItem.hpp"

class Pacman: public DynamicItem {
private:
	int m_lives;
	bool m_isSuper;
	int m_superCounter;

public:
	//CONSTRUCTOR
	Pacman(glm::vec2 position, std::string name = "player", uint score = 0, enum ITEM_SYNTAX type = PACMAN, int lives = 3, bool isSuper = false):
		DynamicItem(position, name, score, type),
		m_lives(lives),
		m_isSuper(isSuper),
		m_superCounter(0)
	{};
	//DESTRUCTOR
	~Pacman() = default;
	
	//GETTERS
	int getLives() const;
	bool isSuper() const;
	int getSuperCounter() const;

	//SETTERS
	inline void updateLives(const int addLife) {
		m_lives += addLife;
	}

	inline void updateIsSuper(const bool isSuper) {
		m_isSuper = isSuper;
	}

	inline void updateSuperCounter(const int time) {
		m_superCounter += time;
	}
};

#endif /* PACMAN_HPP */
